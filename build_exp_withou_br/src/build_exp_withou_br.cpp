#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <map>
using namespace std;

int main() {
	deque<string> d;
	stack<string> s;
	map<string, int> m = {{"-", 1}, {"+", 1}, {"*", 2}, {"/", 2}};
	string num;
	int n;
	cin >> num;
	cin >> n;
	d.push_front(num);
	for (int i = 0; i < n; ++i) {

		string a;
		string op;
		cin >> op;
		cin >> a;
		if (!s.empty() && m[op] > m[s.top()]) {
			d.push_front("(");
			d.push_back(")");
		}
		s.push(op);
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
