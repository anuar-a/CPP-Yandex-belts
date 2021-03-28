#include "search_server.h"
#include "iterator_range.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <string_view>
#include <numeric>



vector<string> SplitIntoWords(const string& line) {
  istringstream words_input(line);
  return {istream_iterator<string>(words_input), istream_iterator<string>()};
}

void AddQueriesStreamSingleThread(
  istream& query_input, ostream& search_results_output, Synchronized<InvertedIndex>& index
) {

    vector<size_t> docid_count;
    vector<int64_t> ids;
  for (string current_query; getline(query_input, current_query); ) {
    const auto words = SplitIntoWords(current_query);
    docid_count.assign(docid_count.size(), 0);
    {
    	size_t size;
		{
			size = index.GetAccess().ref_to_value.GetDocumentSize();
		}
		docid_count.assign(size, 0);
		ids.resize(size);
    for (const auto& word : words) {
      for (const auto& [docid, cnt] : index.GetAccess().ref_to_value.Lookup(word)) {
        docid_count[docid]+= cnt;
      }
    }
    }
    iota(ids.begin(), ids.end(), 0);
    partial_sort(
      begin(ids),
      begin(ids) + min(5, static_cast<int>(ids.size())),
	  end(ids),
      [&docid_count](int64_t lhs, int64_t rhs) {
    	return make_pair(docid_count[lhs], -lhs) > make_pair(docid_count[rhs], -rhs);
      }
    );
    //lock_guard<mutex> g(m);
    search_results_output << current_query << ':';
    for (auto& docid : Head(ids, 5)) {
    	if (docid_count[docid] == 0) {
    		break;
    	}
      search_results_output << " {"
        << "docid: " << docid << ", "
        << "hitcount: " << docid_count[docid] << '}';
    }
    search_results_output << endl;
  }
}

void UpdateDocumentBaseSingleThread(istream& document_input, Synchronized<InvertedIndex>& index) {
  InvertedIndex new_index(document_input);
  swap(index.GetAccess().ref_to_value, new_index);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
	futures.push_back(async(UpdateDocumentBaseSingleThread, ref(document_input), ref(index)));
}

void SearchServer::AddQueriesStream(
  istream& query_input, ostream& search_results_output
) {
	futures.push_back(async(AddQueriesStreamSingleThread, ref(query_input), ref(search_results_output), ref(index)));
}



InvertedIndex::InvertedIndex(istream& document_input) {
	for (string current_document; getline(document_input, current_document); ) {

  docs.push_back(current_document);
  const size_t docid = docs.size() - 1;
  for (const auto& word : SplitIntoWords(current_document)) {
    if (!index[word].empty() && index[word].back().first == docid){
    	index[word].back().second++;
    } else {
    	index[word].push_back({docid, 1});
    }
  }
	}
}
//
const vector<pair<size_t, size_t>> & InvertedIndex::Lookup(const string& word) const {
  if (auto it = index.find(word); it != index.end()) {
    return it->second;
  } else {
	  static vector<pair<size_t, size_t>> dummy;
    return dummy;
  }
}
