#include <iostream>
#include <limits>
#include <optional>
using namespace std;

optional<int64_t> Sum(int64_t a, int64_t b) {
	if (a > 0 && b > 0) {
		if (a > numeric_limits<int64_t>::max() - b) {
			return nullopt;
		}
	} else if (a < 0 && b < 0) {
		if (a < numeric_limits<int64_t>::min() - b) {
			return nullopt;
		}
	}
	return a + b;
}
int main() {
	int64_t a, b;
	cin >> a >> b;
	if (auto r = Sum(a, b); r.has_value()) {
		cout << r.value() << endl;
	} else {
		cout << "Overflow!" << endl;
	}
	return 0;
}
