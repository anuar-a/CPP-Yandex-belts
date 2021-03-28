#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
	int l = prefix.end() - prefix.begin();
	auto it1 = lower_bound(range_begin, range_end, prefix, [=](const string& s1, const string& prefix) {return s1.substr(0, l) < prefix;});
	auto it2 = upper_bound(range_begin, range_end, prefix, [=](const string& prefix, const string& s2) {return prefix < s2.substr(0, l);});
	//auto res = equal_range(range_begin, range_begin, prefix, [](const string& s1, const string& prefix) {return s1[0] + s1[1] < prefix;});
	return make_pair(it1, it2);
}

int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;


  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}
