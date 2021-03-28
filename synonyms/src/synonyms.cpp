#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void Count (const string& word, const set<set<string>>& s) {
	int count = 0;
	for (const auto& item : s) {
		if (item.count(word) > 0) {
			count++;
		}
	}
	cout << count << endl;
}

bool Check (const string& word1, const string& word2, const set<set<string>>& s) {
	set<string> temp;
	temp.insert(word1);
	temp.insert(word2);
	for (const auto& each : s) {
		if (each == temp) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	string command, word, word1, word2;
	set<set<string>> s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> command;
		if (command == "ADD") {
			set<string> v;
			cin >> word1 >> word2;
			v.insert(word1);
			v.insert(word2);
			s.insert(v);
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
