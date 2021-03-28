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

SearchServer::SearchServer(istream& document_input) {
  UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
  InvertedIndex new_index;

  for (string current_document; getline(document_input, current_document); ) {
    new_index.Add(move(current_document));
  }

  index = move(new_index);
}

void SearchServer::AddQueriesStream(
  istream& query_input, ostream& search_results_output
) {
    vector<size_t> docid_count(index.GetDocumentSize(), 0);
    vector<int64_t> ids(index.GetDocumentSize());
  for (string current_query; getline(query_input, current_query); ) {
    const auto words = SplitIntoWords(current_query);
    docid_count.assign(docid_count.size(), 0);
    for (const auto& word : words) {
      for (const auto& [docid, cnt] : index.Lookup(word)) {
        docid_count[docid]+= cnt;
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

void InvertedIndex::Add(const string& document) {
  docs.push_back(document);

  const size_t docid = docs.size() - 1;
  for (const auto& word : SplitIntoWords(document)) {
    if (!index[word].empty() && index[word].back().first == docid){
    	index[word].back().second++;
    } else {
    	index[word].push_back({docid, 1});
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
