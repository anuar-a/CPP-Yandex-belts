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

  // �������� ������ � ������� �����������
  // � ������� ����������� � ������� ��� �������������
  Id Add(T object) {
	  d.push_back({move(object),0});
	  //priorities.push_back(0);
	  //validity.push_back(true);
	  const auto size = d.size() - 1;
	  s.insert({0, static_cast<Id>(size)});
	  return static_cast<Id>(size);
  }

  // �������� ��� �������� ��������� [range_begin, range_end)
  // � ������� �����������, ������� �������� �� ��������������
  // � �������� [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end,
           IdOutputIt ids_begin) {
	  while (range_begin != range_end) {
		  *(ids_begin++) = Add(move(*range_begin++));
	  }
  }

  // ����������, ����������� �� ������������� ������-����
  // ����������� � ���������� �������
  bool IsValid(Id id) const {
	  return d[id].second >= 0;
  }

  // �������� ������ �� ��������������
  const T& Get(Id id) const {
	  return d[id].first;
  }

  // ��������� ��������� ������� �� 1
  void Promote(Id id) {
	  const auto priority = d[id].second;
	  s.erase({priority, id});
	  s.insert({priority + 1, id});
	  ++d[id].second;
  }

  // �������� ������ � ������������ ����������� � ��� ���������
  pair<const T&, int> GetMax() const {
	  return {d[prev(s.end())->second].first, prev(s.end())->first};
  }

  // ���������� GetMax, �� ������� ������� �� ����������
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
  // ��������� ���� � ������
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
  using string::string;  // ��������� ������������ ������������ ������
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
