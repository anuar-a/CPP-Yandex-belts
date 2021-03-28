#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	int q, qty;
	set<string> stops;
	map <set<string>, int> stop_to_bus;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> qty;
		set<string> stops;
		for (int j = 0; j < qty; ++j) {
			string stop;
			cin >> stop;
			stops.insert(stop);
		}
		if (stop_to_bus.count(stops) == 1) {
			cout << "Already exists for " << stop_to_bus[stops] << endl;
		} else {
			int cur_size = stop_to_bus.size();
			stop_to_bus[stops] = cur_size + 1;
			cout << "New bus " << cur_size + 1 << endl;
		}
	}
	return 0;
}
