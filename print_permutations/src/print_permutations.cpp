#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintVector (const vector<int>& v) {
	for (auto& item : v) {
		cout << item << " ";
	}
	cout << endl;
}
//
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		v.push_back(i);
	}
	sort(v.rbegin(), v.rend());
	do {
	       PrintVector(v);
	    } while(prev_permutation(v.begin(),
	    						 v.end()));
	return 0;
}
