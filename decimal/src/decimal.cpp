#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream input;
	double value;
	cout << fixed << setprecision(3);
	while (input >> value) {
		cout << value << endl;
	}
	return 0;
}
