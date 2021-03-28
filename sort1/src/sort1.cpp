#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Comp (int i, int j) {
	if (i < 0) {
		i = i * -1;
	}
	if (j < 0) {
		j = j * -1;
	}
	return i < j;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v) {
		cin >> i;
	}
	sort(v.begin(), v.end(), Comp);
	for (const auto& item : v) {
		cout << item << " ";
	}
	return 0;
}
