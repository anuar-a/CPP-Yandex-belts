#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
	string first_name;
	string last_name;
	int day;
	int month;
	int year;
};

int main() {
	int n, m, new_num;
	string command;
	cin >> n;
	vector<Student> v(n);
	for (auto& item : v) {
		cin >> item.first_name;
		cin >> item.last_name;
		cin >> item.day;
		cin >> item.month;
		cin >> item.year;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> command;
		if (command == "name") {
			cin >> new_num;
			const int& num = new_num - 1;
			if (num < 0 || num > n - 1) {
				cout << "bad request" << endl;
			} else {
				cout << v[num].first_name << " " << v[num].last_name << endl;
			}
		} else if (command == "date") {
			cin >> new_num;
			const int& num = new_num - 1;
			if (num < 0 || num > n - 1) {
				cout << "bad request" << endl;
			} else {
				cout << v[num].day << "." << v[num].month << "." << v[num].year << endl;
			}

		} else {
			cin >> new_num;
			cout << "bad request" << endl;
		}
	}
	return 0;
}
