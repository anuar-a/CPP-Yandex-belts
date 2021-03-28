#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int q, n;
	vector<string> stops;
	string command, bus, stop;
	cin >> q;
	map<string, vector<string>> bus_to_stop;
	map<string, vector<string>> stop_to_bus;
	for (int i = 0; i < q; ++i) {
		cin >> command;
		if (command == "NEW_BUS") {
			cin >> bus >> n;
			// stops.clear();
			//stops.resize(n, "");
			/*for (auto& s : stops) {
				cin >> s;

			}*/
			for (int j = 0; j < n; ++j) {
				cin >> stop;
				bus_to_stop[bus].push_back(stop);
				stop_to_bus[stop].push_back(bus);
			}
			//bus_to_stop[bus] = stops;

		} else if (command == "BUSES_FOR_STOP") {
			cin >> stop;
			if (stop_to_bus.count(stop) == 0) {
				cout << "No stop" << endl;
			} else {
				for (const auto& s : stop_to_bus[stop]) {
					cout << s << " ";
				}
				cout << endl;
			}



		} else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			if (bus_to_stop.count(bus) == 0) {
				cout << "No bus" << endl;
			} else {
				for (const auto& item : bus_to_stop[bus]) {
					cout << "Stop " << item << ": ";
					if (stop_to_bus[item].size() == 1 && stop_to_bus[item][0] == bus) {
						cout << "no interchange" << endl;
					} else {
						for (const auto& each : stop_to_bus[item]) {
							if (each != bus) {
								cout << each << " ";
							}
						}
						cout << endl;
					}
				}
			}
		} else if (command == "ALL_BUSES") {
			if (bus_to_stop.size() == 0) {
				cout << "No buses" << endl;
			} else {
				for (const auto& each : bus_to_stop) {
					cout << "Bus " << each.first << ": ";
					for (const auto& every : bus_to_stop[each.first]) {
						cout << every << " ";
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}
