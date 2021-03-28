#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Athlete {
	int number;
	int next;
};

int main() {
	list<int> lst;
	vector<list<int>::iterator> v(100000, lst.end());
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int number, next;
		cin >> number;
		cin >> next;
		v[number] = lst.insert(v[next], number);
	}
	for (auto& item : lst) {
		cout << item << endl;
	}
	return 0;
}
