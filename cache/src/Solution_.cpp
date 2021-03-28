#include "Common.h"

#include <mutex>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

class LruCache : public ICache {

public:
  using Id = int;
  using Rank = int;


  LruCache(
      shared_ptr<IBooksUnpacker> books_unpacker,
      const Settings& settings
  ) : books_unpacker_(books_unpacker), settings_(settings), free_memory(settings.max_memory) {
    // реализуйте метод
  }

  BookPtr GetBook(const string& book_name) override {
    // реализуйте метод
	lock_guard<mutex> g(m);
	for (int i = 0; i < d.size(); ++i) {
		if (d[i].first == book_name) {
			MaximizeRank(i);
			return d[i].second;
		}
	}
	return AddBook(book_name);
  }
private:
  shared_ptr<IBooksUnpacker> books_unpacker_;
  const Settings& settings_;
  set<pair<Rank, Id>> s;
  vector<pair<string, BookPtr>> d;
  mutex m;
  size_t free_memory;

  void MaximizeRank(Id id) {
	  for (auto& item : s) {
		  if (item.second == id) {
			  s.erase(item);
			  break;
		  }
	  }
	  s.insert({(s.empty()) ? 0 : s.rbegin()->first + 1, id});
  }

  BookPtr AddBook(const string& book_name) {
	  BookPtr book = books_unpacker_->UnpackBook(book_name);
	  size_t size = book->GetContent().size();
	  if (size > settings_.max_memory) {
		  ClearCache();
		  return move(book);
	  }
	  if (size > free_memory) {
		  if (size == settings_.max_memory) {
			  ClearCache();
		  } else {
			  FreeCache(size);
		  }
	  }
	  d.push_back({book_name, move(book)});

	  s.insert({(s.empty()) ? 0 : s.rbegin()->first + 1, d.size() - 1});
	  free_memory -= d[d.size() - 1].second->GetContent().size();

	  return d[d.size() - 1].second;
  }

  void ClearCache() {
	  s.clear();
	  d.clear();
	  free_memory = settings_.max_memory;
  }

  void FreeCache(size_t mem) {
	  do {
		  auto id = s.begin()->second;
		  free_memory += d[id].second->GetContent().size();
		  d.erase(d.begin() + id);
		  s.erase(s.begin());
	  }
	  while (mem > free_memory);
  }
};


unique_ptr<ICache> MakeCache(
    shared_ptr<IBooksUnpacker> books_unpacker,
    const ICache::Settings& settings
) {
  // реализуйте функцию
	return make_unique<LruCache>(books_unpacker, settings);
}
