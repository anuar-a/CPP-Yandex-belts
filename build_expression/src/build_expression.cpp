#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	deque<string> d;
	string num;
	int n;
	cin >> num;
	cin >> n;
	d.push_front(num);
	for (int i = 0; i < n; ++i) {
		d.push_front("(");
		d.push_back(")");
		string a;
		string op;
		cin >> op;
		cin >> a;
		d.push_back(" ");
		d.push_back(op);
		d.push_back(" ");
		d.push_back(a);
	}
	for (auto i : d) {
		cout << i;
	}
	return 0;
}
