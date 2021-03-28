#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

struct Record {
  string id;
  string title;
  string user;
  int timestamp;
  int karma;
};

// Реализуйте этот класс
class Database {
public:
  bool Put(const Record& record) {
	  auto [it, is_inserted] = data.insert({record.id, {record}});
	  if (!is_inserted) {
		  return false;
	  }
	  auto &item = it->second;
	  Record* ptr = &item.record;
	  item.tstamp_iterator = tstamp_index.insert({record.timestamp, ptr});
	  item.karma_iterator = karma_index.insert({record.karma, ptr});
	  item.user_iterator = user_index.insert({record.user, ptr});
	  return true;
  }

  const Record* GetById(const string& id) const {
	  auto it = data.find(id);
	  if (it == data.end()) {
		  return nullptr;
	  }
	  return &it->second.record;
  }

  bool Erase(const string& id) {
	  auto it = data.find(id);
	  if (it == data.end()) {
		  return false;
	  }
	  auto &item = it->second;
	  tstamp_index.erase(item.tstamp_iterator);
	  karma_index.erase(item.karma_iterator);
	  user_index.erase(item.user_iterator);
	  data.erase(it);
	  return true;
  }

  template <typename Callback>
  void RangeByTimestamp(int low, int high, Callback callback) const {
	  auto it_low = tstamp_index.lower_bound(low);
	  auto it_high = tstamp_index.upper_bound(high);
	  for (auto it = it_low; it != it_high; ++it) {
		  if (!callback(*it->second)) {
			  break;
		  }
	  }
  }

  template <typename Callback>
  void RangeByKarma(int low, int high, Callback callback) const {
	  auto it_low = karma_index.lower_bound(low);
	  auto it_high = karma_index.upper_bound(high);
	  for (auto it = it_low; it != it_high; ++it) {
		  if (!callback(*it->second)) {
			  break;
		  }
	  }
  }

  template <typename Callback>
  void AllByUser(const string& user, Callback callback) const {
	  auto [it_low, it_high] = user_index.equal_range(user);
	  for (auto it = it_low; it != it_high; ++it) {
		  if (!callback(*it->second)) {
			  break;
		  }
	  }
  }

private:
  struct Item {
	  Record record;
	  multimap<int, Record*>::iterator tstamp_iterator;
	  multimap<int, Record*>::iterator karma_iterator;
	  multimap<string, Record*>::iterator user_iterator;
  };
  unordered_map<string, Item> data;
  multimap<int, Record*> tstamp_index;
  multimap<int, Record*> karma_index;
  multimap<string, Record*> user_index;
};

void TestRangeBoundaries() {
  const int good_karma = 1000;
  const int bad_karma = -10;

  Database db;
  db.Put({"id1", "Hello there", "master", 1536107260, good_karma});
  db.Put({"id2", "O>>-<", "general2", 1536107260, bad_karma});

  int count = 0;
  db.RangeByKarma(bad_karma, good_karma, [&count](const Record&) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestSameUser() {
  Database db;
  db.Put({"id1", "Don't sell", "master", 1536107260, 1000});
  db.Put({"id2", "Rethink life", "master", 1536107260, 2000});

  int count = 0;
  db.AllByUser("master", [&count](const Record&) {
    ++count;
    return true;
  });

  ASSERT_EQUAL(2, count);
}

void TestReplacement() {
  const string final_body = "Feeling sad";

  Database db;
  db.Put({"id", "Have a hand", "not-master", 1536107260, 10});
  db.Erase("id");
  db.Put({"id", final_body, "not-master", 1536107260, -10});

  auto record = db.GetById("id");
  ASSERT(record != nullptr);
  ASSERT_EQUAL(final_body, record->title);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestRangeBoundaries);
  RUN_TEST(tr, TestSameUser);
  RUN_TEST(tr, TestReplacement);
  return 0;
}
