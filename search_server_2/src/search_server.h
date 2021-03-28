#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <mutex>
#include <future>
#include <functional>
using namespace std;

template <typename T>
class Synchronized {
public:
  explicit Synchronized(T initial = T()):value(move(initial)) {

  }

  struct Access {
    T& ref_to_value;
	lock_guard<mutex> g;
  };

  Access GetAccess() {
	  return {value, lock_guard(m)};
  }
private:
  mutex m;
  T value;
};

class InvertedIndex {
public:
  InvertedIndex() = default;
  explicit InvertedIndex(istream& document_input);
  const vector<pair<size_t, size_t>> & Lookup(const string& word) const ;

  const string& GetDocument(size_t id) const {
    return docs[id];
  }

  const size_t GetDocumentSize() const {
    return docs.size();
  }

private:
  map<string, vector<pair<size_t, size_t>>> index;
  vector<string> docs;
  //mutex mut;
};

class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input):index(InvertedIndex(document_input)) {
  }
  void UpdateDocumentBase(istream& document_input);
  void AddQueriesStream(istream& query_input, ostream& search_results_output);
  //void AddQueriesStreamSingleThread(istream& query_input, ostream& search_results_output);

private:
  Synchronized<InvertedIndex> index;
  mutex m;
  vector<future<void>> futures;
};
