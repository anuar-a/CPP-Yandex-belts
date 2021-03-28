#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> BuildCharCounters (const string& word) {
	map<char, int> map_char;
	for (auto c : word){
		map_char[c] = count(word.begin(), word.end(), c);
	}
	return map_char;
}

int main() {
	int q;
	string w1, w2;
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> w1 >> w2;
		if (BuildCharCounters(w1) == BuildCharCounters(w2)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
