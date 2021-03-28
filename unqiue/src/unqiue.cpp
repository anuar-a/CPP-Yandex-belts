#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (auto& i: v) {
		cin >> i;
	}
	set<string> s(v.begin(), v.end());
	cout << s.size();
	return 0;
}
