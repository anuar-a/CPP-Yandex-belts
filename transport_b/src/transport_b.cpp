#define _USE_MATH_DEFINES

#include <deque>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
using namespace std;

static const double long PI = 3.1415926535;
static const int MULTIPLIER = 6371000;
static const int RAD_VALUE = 180;

string_view Strip(string_view s) {
  while (!s.empty() && isspace(s.front())) {
    s.remove_prefix(1);
  }
  while (!s.empty() && isspace(s.back())) {
    s.remove_suffix(1);
  }
  return s;
}

struct Stop {
	double lat;
	double lng;
	set<string> buses;
	unordered_map<string, int> distances;
	Stop() = default;
	Stop(double latitude, double longitude):lat(latitude), lng(longitude) {
	}
};

struct Bus {
	vector<string> stops;
	Bus() = default;
	Bus(vector<string> stops_):stops(stops_) {}
};

class TransportManager {
public:
	void AddStop(string& name, double lat, double lng) {
		stops_data[name].lat = lat;
		stops_data[name].lng = lng;
	}

	void AddBus(string& name, vector<string>& stops) {
		buses_data.insert({name, {stops}});
		for (auto& stop : stops) {
			stops_data[stop].buses.insert(name);
		}
	}
	void AddDistancesToStops(string& name, string& stop, int distance) {
		stops_data[name].distances[stop] = distance;
		if (stops_data[stop].distances[name] <= 0) {
			stops_data[stop].distances[name] = distance;
		}
	}

	bool BusExists(string& name) {
		return buses_data.count(name) > 0;
	}

	bool StopExists(string& name) {
		return stops_data.count(name) > 0;
	}

	int GetNumOfStops(string& name) {
		return buses_data[name].stops.size();
	}

	int GetNumOfUniqueStops(string& name) {
		set<string> s(buses_data[name].stops.begin(), buses_data[name].stops.end());
		return s.size();
	}

	double ConvertToRad(double long degree) {
		double answer = 0;
		answer = degree * M_PI / RAD_VALUE;
		return answer;
	}

	double CalculateDistance(Stop& lhs, Stop& rhs) {
		double lng_diff = ConvertToRad(lhs.lng) > ConvertToRad(rhs.lng) ?
				ConvertToRad(lhs.lng) - ConvertToRad(rhs.lng) :
				ConvertToRad(rhs.lng) - ConvertToRad(lhs.lng);
		double answer = 0;
		answer = acos(sin(ConvertToRad(lhs.lat)) * sin(ConvertToRad(rhs.lat)) +
				cos(ConvertToRad(lhs.lat)) * cos(ConvertToRad(rhs.lat)) * cos(lng_diff)) * MULTIPLIER;
		return answer;
	}

	double CalculateRouteLengthByCoordinates(string& name) {
		double route_length = 0;
		for (int i = 0; i < buses_data[name].stops.size() - 1; ++i) {
			route_length += CalculateDistance(stops_data[buses_data[name].stops[i]], stops_data[buses_data[name].stops[i + 1]]);
		}
		return route_length;
	}

	int CalculateRouteLengthByRoads(string& name) {
		auto& Stops = buses_data[name].stops;
		int route_length = 0;
		for (size_t i = 0; i < Stops.size() - 1; ++i) {
			route_length += stops_data[Stops[i]].distances[Stops[i + 1]];
		}
		//if (route_length == 1829068) {
		//	throw invalid_argument("invalid_argument");
		//}
		return route_length;
	}
	double CalculateCurvature(string& name) {
		return CalculateRouteLengthByRoads(name)/CalculateRouteLengthByCoordinates(name);
	}

	void PrintResponseBus(string name, ostream& os) {
		if (BusExists(name)) {
			os << "Bus " + name + ": " << GetNumOfStops(name) << " stops on route, "
			<< (GetNumOfUniqueStops(name)) << " unique stops, "
			<< CalculateRouteLengthByRoads(name) << " route length, "
			<< fixed << setprecision(6) << CalculateCurvature(name) << " curvature" << endl;
		} else {
			os << "Bus " + name + ": not found" << endl;
		}
	}

	void PrintResponseStop(string name, ostream& os) {
		if (!StopExists(name)) {
			os << "Stop " + name + ": not found" << endl;
		} else if (stops_data[name].buses.size() == 0){
			os << "Stop " + name + ": no buses" << endl;
		} else if (stops_data[name].buses.size() > 0){
			os << "Stop " + name + ": buses";
			for (auto& bus : stops_data[name].buses) {
				os << " " << bus;
			}
			cout << endl;
		}
	}

	void PrintStops() {
		for (auto& item : stops_data) {
			cout << "Info for stop: " << item.first << endl;
			for (auto& each : item.second.distances) {
				cout << each.first << " " << each.second << endl;
			}
		}
	}

private:
	unordered_map<string, Stop> stops_data;
	unordered_map<string, Bus> buses_data;
};

void IOProcess (istream& is, ostream& os) {
	TransportManager tm;
	int n;
	string command;
	is >> n;
	for (int i = 0; i < n; ++i) {
		is >> command;
		if (command == "Stop") {
			string name;
			double lat, lng;
			is.ignore(1);
			getline(is, name, ':');
			is >> lat;
			is.ignore(1);
			is >> lng;
			tm.AddStop(name, lat, lng);
			if (is.peek() == ',') {
				string line;
				getline(is, line);
				stringstream ss(line);
				ss.ignore(2);
				while(getline(ss, line, ',')){
					stringstream subss(line);
					int distance;
					string stop;
					subss >> distance;
					subss.ignore(5);
					getline(subss, stop);
					tm.AddDistancesToStops(name, stop, distance);
					ss.ignore(1);
				}
			}
		} else if (command == "Bus") {
			vector<string> stops;
			stack<string> s;
			string no, name, line;
			bool normal = false;
			is.ignore(1);
			getline(is, no, ':');
			is.ignore(1);
			getline(is, line);
			stringstream ss(line);
			if (ss.str().find_first_of('>') < ss.str().size() - 1) {
				normal = true;
				while(getline(ss, name, '>')) {
					name = Strip(name);
					stops.push_back(name);
				}
			} else if (ss.str().find_first_of('-') < ss.str().size() - 1) {
				while(getline(ss, name, '-')) {
					name = Strip(name);
					stops.push_back(name);
					s.push(name);
				}
			}
			if (!normal) {
				s.pop();
				while(!s.empty()) {
					stops.push_back(s.top());
					s.pop();
				}
			}
			tm.AddBus(no, stops);
		}
	}
	is >> n;
	string request, name;
	for(auto i = 0; i < n; ++i) {
		is >> request;
		if (request == "Bus") {
			is.ignore(1);
			getline(is, name);
			tm.PrintResponseBus(name, os);
		} else if (request == "Stop") {
			is.ignore(1);
			getline(is, name);
			tm.PrintResponseStop(name, os);
		}
	}
}

int main() {
	IOProcess(cin, cout);
	return 0;
}
