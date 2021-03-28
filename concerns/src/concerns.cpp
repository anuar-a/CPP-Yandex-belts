#include <iostream>
#include <string>
#include <vector>
using namespace std;
//
int main() {
	int q, num, current_month = 0, next_month = 1;
	string command, activity;
	cin >> q;
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> days(31);
	for (int i = 0; i < q; i++) {
		cin >> command;
		if (command == "ADD") {
			cin >> num >> activity;
			days[num - 1].push_back(activity);
		} else if (command == "DUMP") {
			cin >> num;
			cout << days[num - 1].size() << " ";
			for (auto s : days[num - 1]) {
				cout << s << " ";
			}
			cout << endl;
		} else if (command == "NEXT") {
			if (current_month == 11) {
				next_month = 0;
			}
			if (months[next_month] > months[current_month]) {
				days.resize(days.size() + months[next_month] - months[current_month]);
			} else if (months[next_month] < months[current_month]) {
				for (int j = 0; j < months[current_month] - months[next_month]; j++) {
					for (auto s : days[months[next_month] + j]) {
						days[months[next_month] - 1].push_back(s);
					}
				}
				days.resize(months[current_month + 1]);
			}
			if (current_month == 11) {
				current_month = 0;
				next_month = 1;
			} else {
				current_month++;
				next_month++;
			}


		}

	}
	return 0;
}
