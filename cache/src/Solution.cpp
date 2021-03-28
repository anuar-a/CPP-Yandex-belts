#include "Common.h"

#include <mutex>
#include <unordered_map>
#include <list>
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
	auto it = cache.find(book_name);
	if (it != cache.end()) {
		it->second.index_itr = MaximizeRank(it->second.index_itr);
		return  it->second.book_ptr;
	}
	return AddBook(book_name);
  }
private:
  struct Item {
	  BookPtr book_ptr;
	  list<Item*>::iterator index_itr;
  };
  shared_ptr<IBooksUnpacker> books_unpacker_;
  const Settings& settings_;
  unordered_map<string, Item> cache;
  list<Item*> indices;
  mutex m;
  size_t free_memory;

  list<Item*>::iterator MaximizeRank(list<Item*>::iterator it) {
	  auto item = *it;
	  indices.erase(it);
	  indices.push_front(item);
	  return indices.begin();
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
	  auto [it, is_inserted] = cache.insert({book_name, {move(book)}});
	  indices.push_front(&it->second);
	  cache[book_name].index_itr = indices.begin();
	  free_memory -= size;
	  return it->second.book_ptr;
  }

  void ClearCache() {
	  cache.clear();
	  indices.clear();
	  free_memory = settings_.max_memory;
  }

  void FreeCache(size_t mem) {
	  while (mem > free_memory) {
		  auto item = indices.back();
		  indices.pop_back();
		  free_memory += item->book_ptr->GetContent().size();
		  cache.erase(item->book_ptr->GetName());
	  }
  }
};


unique_ptr<ICache> MakeCache(
    shared_ptr<IBooksUnpacker> books_unpacker,
    const ICache::Settings& settings
) {
  // реализуйте функцию
	return make_unique<LruCache>(books_unpacker, settings);
}
