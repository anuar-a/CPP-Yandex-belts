#include <iostream>
#include <string>
#include <map>
using namespace std;

void PrintMap (const map<string, string>& m) {
	for (auto item : m) {
		cout << item.first << "/" << item.second << endl;
	}
}

bool Exists (const map<string, string>& m, const string& country) {
	for (const auto& item : m) {
		if (item.first == country){
			return true;
		}
	}
	return false;
}

int main() {
	int q;
	map<string, string> countries_map;
	string command, country, capital, old_country_name, new_country_name;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			cin >> country >> capital;
			if (Exists(countries_map, country) == false) {
				countries_map[country] = capital;
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			} else if (countries_map[country] == capital) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			} else {
				cout << "Country " << country << " has changed its capital from " << countries_map[country] << " to " << capital << endl;
				countries_map[country] = capital;
			}
		} else if (command == "RENAME") {
			cin >> old_country_name >> new_country_name;
			if (old_country_name == new_country_name || Exists(countries_map, old_country_name) == false || Exists(countries_map, new_country_name) == true) {
				cout << "Incorrect rename, skip" << endl;
			} else if (countries_map[old_country_name] != ""){
				cout << "Country " << old_country_name << " with capital " << countries_map[old_country_name] << " has been renamed to " << new_country_name << endl;
				countries_map[new_country_name] = countries_map[old_country_name];
				countries_map.erase(old_country_name);
			}
		} else if (command == "ABOUT") {
			cin >> country;
			if (Exists(countries_map, country) == false) {
				cout << "Country " << country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital " << countries_map[country] << endl;
			}
		} else if (command == "DUMP") {
			if (countries_map.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else {
				PrintMap(countries_map);
			}
		}
	}
	return 0;
}
