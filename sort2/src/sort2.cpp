#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (auto& i : v) {
		cin >> i;
	}
	sort(v.begin(), v.end(), [](string s1, string s2) {
		for (auto& a : s1) {
			a = tolower(a);
		}
		for (auto& b : s2) {
			b = tolower(b);
		}
		return s1 < s2;
	});
	for (const auto& item : v) {
		cout << item << " ";
	}
	return 0;
}
