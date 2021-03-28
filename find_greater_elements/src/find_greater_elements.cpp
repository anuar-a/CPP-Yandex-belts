#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	vector<T> result;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (*i > border) {
			result.push_back(*i);
		}
	}
	return result;
}

int main() {
	string s = "Test";
	string st(s.begin(), --s.end());
	cout << st << endl;
	for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
	cout << x << " ";
	}
	cout << endl;
    string to_find = "Python";
	cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
	return 0;
}
