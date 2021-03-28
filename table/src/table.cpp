#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	ifstream input("input.txt");
	int n, m, value;
	input >> n;
	input >> m;
	for (int j = 0; j < n; ++j) {
	for (int i = 0; i < m; ++i) {
		input >> value;
		input.ignore(1);
		if (i < m - 1) {
			cout << setw(10) << value << ' ';
		} else {
			cout << setw(10) << value;
		}
	}
	if (j < n - 1) {
		cout << endl;
	}
	}
	return 0;
}
