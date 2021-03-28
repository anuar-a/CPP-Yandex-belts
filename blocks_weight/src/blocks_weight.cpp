#include <iostream>
#include <vector>
using namespace std;

int main() {
	uint64_t r, n, w, h, d;
	// vector<vector<long long int>> v;
	uint64_t m = 0;
	cin >> n;
	cin >> r;
	// v.assign(3, vector<long long int>(3));
	for (int i = 0; i < n; ++i) {
		// cin >> v[i][0];
		// cin >> v[i][1];
		// cin >> v[i][2];
		cin >> w;
		cin >> h;
		cin >> d;
		m += r * w * h * d;
	}
	/* for (auto& item : v) {
		m += r * item[0] * item[1] * item[2];
	} */
	cout << m << endl;
	return 0;
}
