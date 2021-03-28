#include <iostream>
#include <vector>
using namespace std;

bool IsPalindrom(string s) {
	string s2;
	for (int i = s.size() - 1; i >= 0; i--) {
		s2 += s[i];
	}
	if (s == s2) {
		return true;
	}
	return false;
}

vector <string> PalindromFilter (vector <string> words, int minLength) {
	string s;
	vector <string> answer;
	for (auto str: words) {
		if (IsPalindrom(str) && (str.size() >= minLength)){
			answer.push_back(str);
		}
	}
	return answer;
}

int main() {
	vector <string> words, result;
	result = PalindromFilter({"abacaba", "aba"}, 5);
	for (auto str: result) {
		cout << str;
	}
	return 0;
}
