#include <iostream>
#include <map>
#include <exception>
using namespace std;

template <typename Key, typename Value> Value& GetRefStrict(map<Key, Value>& m, Key i);

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key i) {
	if (m.count(i) > 0) {
	return m.at(i);
	} else {
		throw runtime_error("");
	}
}


int main() {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}
