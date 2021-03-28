#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
using namespace std;

void Count(const string& word, map<string, set<string>>& s) {
	cout << s[word].size() << endl;
}

bool Check(const string& word1, const string& word2, map<string, set<string>>& s) {
	for (const auto& each : s[word1]) {
		if (each == word2) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	string command, word, word1, word2;
	map<string, set<string>> s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> command;
		if (command == "ADD") {
			cin >> word1 >> word2;
			s[word1].insert(word2);
			s[word2].insert(word1);
		} else if (command == "COUNT") {
			cin >> word;
			Count(word, s);
		} else if (command == "CHECK") {
			cin >> word1 >> word2;
			if (Check(word1, word2, s) == true) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
