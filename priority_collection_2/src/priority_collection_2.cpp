#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

template <typename T>
class PriorityCollection {
public:
  using Id = int;

  // Добавить объект с нулевым приоритетом
  // с помощью перемещения и вернуть его идентификатор
  Id Add(T object) {
	  d.push_back({move(object),0});
	  //priorities.push_back(0);
	  //validity.push_back(true);
	  const auto size = d.size() - 1;
	  s.insert({0, static_cast<Id>(size)});
	  return static_cast<Id>(size);
  }

  // Добавить все элементы диапазона [range_begin, range_end)
  // с помощью перемещения, записав выданные им идентификаторы
  // в диапазон [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end,
           IdOutputIt ids_begin) {
	  while (range_begin != range_end) {
		  *(ids_begin++) = Add(move(*range_begin++));
	  }
  }

  // Определить, принадлежит ли идентификатор какому-либо
  // хранящемуся в контейнере объекту
  bool IsValid(Id id) const {
	  return d[id].second >= 0;
  }

  // Получить объект по идентификатору
  const T& Get(Id id) const {
	  return d[id].first;
  }

  // Увеличить приоритет объекта на 1
  void Promote(Id id) {
	  const auto priority = d[id].second;
	  s.erase({priority, id});
	  s.insert({priority + 1, id});
	  ++d[id].second;
  }

  // Получить объект с максимальным приоритетом и его приоритет
  pair<const T&, int> GetMax() const {
	  return {d[prev(s.end())->second].first, prev(s.end())->first};
  }

  // Аналогично GetMax, но удаляет элемент из контейнера
  pair<T, int> PopMax() {
	  const auto idx = s.rbegin()->second;
	  const auto priority = s.rbegin()->first;
	  auto it = prev(s.end());
	  s.erase(it);
	  //validity[idx] = false;
	  d[idx].second = -1;
	  return {move(d[idx].first), priority};
  }

private:
  // Приватные поля и методы
  vector<bool> validity;
  vector<int> priorities;
  struct Item {
      int priority;
      Id idx;
      bool operator<(const Item& other) const {
    	  return vector<int> {priority, idx} < vector<int> {other.priority, other.idx};
      }
    };
  set<pair<Id, int>> s;
  vector<pair<T, int>> d;
};


class StringNonCopyable : public string {
public:
  using string::string;  // Позволяет использовать конструкторы строки
  StringNonCopyable(const StringNonCopyable&) = delete;
  StringNonCopyable(StringNonCopyable&&) = default;
  StringNonCopyable& operator=(const StringNonCopyable&) = delete;
  StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
  PriorityCollection<StringNonCopyable> strings;
  const auto white_id = strings.Add("white");
  const auto yellow_id = strings.Add("yellow");
  const auto red_id = strings.Add("red");
  strings.Promote(yellow_id);
  for (int i = 0; i < 2; ++i) {
    strings.Promote(red_id);
  }
  strings.Promote(yellow_id);
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "red");
    ASSERT_EQUAL(item.second, 2);
  }
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "yellow");
    ASSERT_EQUAL(item.second, 2);
  }
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "white");
    ASSERT_EQUAL(item.second, 0);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
