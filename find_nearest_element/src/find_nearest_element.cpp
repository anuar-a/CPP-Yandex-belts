#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
	auto itself = find(numbers.begin(), numbers.end(), border);
	if (itself != numbers.end()) {
		return itself;
	} else if (numbers.empty()) {
		return numbers.end();
	} else {
		auto next_it = upper_bound(numbers.begin(), numbers.end(), border);
		if (border < *numbers.begin()) {
			return numbers.begin();
		} else if (border > *prev(numbers.end())) {
			return prev(numbers.end());
		} else {
			if (border - *prev(next_it) <= *next_it - border) {
				return prev(next_it);
			} else {
				return next_it;
			}
		}
	}
}
//
int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;
  //
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
