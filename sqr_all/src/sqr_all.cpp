#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <utility>
using namespace std;

template <typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second >& p2);
template <typename Item> vector<Item> operator*(const vector<Item>& v1, const vector<Item>& v2);
template <typename Key, typename Value> map<Key, Value> operator*(const map<Key, Value>& m1, const map<Key, Value>& m2);
template <typename Collection> Collection Sqr(const Collection& c);

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second >& p2) {
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;
	return {f, s};
}

template <typename Item>
vector<Item> operator*(const vector<Item>& v1, const vector<Item>& v2) {
	int n = static_cast<int>(v1.size());
	vector<Item> v(n);
	for (int i = 0; i < n; ++i) {
		v[i] = v1[i] * v2[i];
	}
	return v;
}

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& m1, const map<Key, Value>& m2) {
	map<Key, Value> m;
	for(auto& each : m1) {
		m[each.first] = each.second * each.second;
	}
	return m;
}

template <typename Collection>
Collection Sqr(const Collection& c) {
	return c * c;
}

int main() {
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
