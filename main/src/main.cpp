#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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

int main() {
	string s;
	cin >> s;
	cout << IsPalindrom(s);
	return 0;
}
