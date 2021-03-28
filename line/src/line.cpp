#include <iostream>
#include <vector>
#include <string>
using namespace std;

void WorryCount(const vector<int>& v) {
	int count = 0;
	for (auto i : v) {
		if (i == 1) {
			count += 1;
		}
	}
	cout << count << endl;
}

void PrintVector(const vector<int>& v) {
	cout << "Vector is: ";
	for (auto s : v) {
		cout << s << " ";
	}
}

int main() {
	int n;
	string command;
	int num;
	cin >> n;
	vector<int> items;
	while (n > 0) {
		cin >> command;
		if (command == "COME") {
			cin >> num;
			if (num > 0) {
				for (int i = 0; i < num; ++i) {
					items.push_back(0);
				}
			} else {
				items.resize(items.size() + num);
			}
		} else if (command == "WORRY") {
			cin >> num;
			items[num] = 1;
		} else if (command == "QUIET") {
			cin >> num;
			items[num] = 0;
		} else if (command == "WORRY_COUNT") {
			WorryCount(items);
		}

		n--;
	}
	return 0;
}
