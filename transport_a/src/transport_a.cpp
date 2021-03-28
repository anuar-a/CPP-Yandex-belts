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
	//string name;
	double lat;
	double lng;

	Stop() = default;
	Stop(double long latitude, double long longitude):lat(latitude), lng(longitude) {
	}
};

struct Bus {
	//string no;
	vector<string> stops;
	Bus() = default;
	Bus(vector<string> stops_):stops(stops_) {}
};

class TransportManager {
public:
	void AddStop(string& name, double long lat, double long lng) {
		stops.insert({name, {lat, lng}});
	}

	void AddBus(string& name, vector<string>& stops) {
		buses.insert({name, {stops}});
	}

	bool BusExists(string& name) {
		return buses.count(name) > 0;
	}

	int GetNumOfStops(string& name) {
		return buses[name].stops.size();
	}

	int GetNumOfUniqueStops(string& name) {
		set<string> s(buses[name].stops.begin(), buses[name].stops.end());
		return s.size();
	}

	double long ConvertToRad(double long degree) {
		double long answer = 0;
		answer = degree * M_PI / RAD_VALUE;
		return answer;
	}

	double long CalculateDistance(Stop& lhs, Stop& rhs) {
		double long lng_diff = ConvertToRad(lhs.lng) > ConvertToRad(rhs.lng) ?
				ConvertToRad(lhs.lng) - ConvertToRad(rhs.lng) :
				ConvertToRad(rhs.lng) - ConvertToRad(lhs.lng);
		double long answer = 0;
		answer = acos(sin(ConvertToRad(lhs.lat)) * sin(ConvertToRad(rhs.lat)) +
				cos(ConvertToRad(lhs.lat)) * cos(ConvertToRad(rhs.lat)) * cos(lng_diff)) * MULTIPLIER;
		return answer;
	}

	double long CalculateRouteLength(string& name) {
		double long route_length = 0;
		for (int i = 0; i < buses[name].stops.size() - 1; ++i) {
			route_length += CalculateDistance(stops[buses[name].stops[i]], stops[buses[name].stops[i + 1]]);
		}
		return route_length;
	}

	string ProcessRequest(string name) {
		string response_stops = to_string(GetNumOfStops(name)) + " stops on route, ";
		string response_unique = to_string(GetNumOfUniqueStops(name)) + " unique stops on route, ";
		string route_length = to_string(CalculateRouteLength(name)) + " route length";
		return response_stops + response_unique + route_length;
	}

	void PrintResponse(string name, ostream& os) {
		//os.precision(6);
		if (!BusExists(name)) {
			os << "Bus " + name + ": not found" << endl;
		} else {
			os << "Bus " + name + ": " + to_string(GetNumOfStops(name)) + " stops on route, " +
					to_string(GetNumOfUniqueStops(name)) + " unique stops, "
					<< fixed << setprecision(6) << CalculateRouteLength(name) << " route length" << endl;
		}
	}

	void PrintStops(ostream& os) {
		os.precision(6);
		for (auto& stop : stops) {
			os << stop.first << " " << stop.second.lat << " " << stop.second.lng << endl;
		}
	}

	void PrintBuses(ostream& os) {
			os.precision(6);
			for (auto& bus : buses) {
				os << bus.first << " ";
				for (auto& stop : bus.second.stops) {
					os << stop << "-";
				}
				os << endl;
			}
		}
private:
	unordered_map<string, Stop> stops;
	unordered_map<string, Bus> buses;
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
			string temp;
			string lat_s;
			double long lat, lng;
			/*do {
				is >> temp;
				if (name != "") {
					name = name + " ";
				}
				name = name + temp;
			} while(temp.back() != ':');
			name = name.substr(0, name.size() - 1);*/
			is.ignore(1);
			getline(is, name, ':');
			is >> lat;
			is.ignore(1);
			is >> lng;
			tm.AddStop(name, lat, lng);
		} else if (command == "Bus") {
			int num, num_unique;
			vector<string> stops;
			deque<string> d;
			stack<string> s;
			string temp;
			string no;
			string name;
			string word;
			string line;
			char delim;
			bool normal = false;
			/*do {
				is >> temp;
				if (no != "") {
					no = no + " ";
				}
				no = no + temp;
			} while(temp.back() != ':');
			no = no.substr(0, no.size() - 1);*/
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
			/*while (ss >> word) {
				if (word == ">") normal = true;
				if (word == ">" || word == "-") {
					while (!d.empty()) {
						if (!name.empty()) {
							name += " ";
						}
						name += d.front();
						d.pop_front();
					}
					stops.push_back(name);
					s.push(name);
					name.clear();
				} else {
					d.push_back(word);
				}
			}
			while (!d.empty()) {
				if (!name.empty()) {
					name += " ";
				}
				name += d.front();
				d.pop_front();
			}
			stops.push_back(name);
			s.push(name);
			name.clear();*/
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
	string request, no;
	for(auto i = 0; i < n; ++i) {
		is >> request;
		if (request == "Bus") {
			is.ignore(1);
			getline(is, no);
			os.precision(6);
			tm.PrintResponse(no, os);
		}
	}
}

int main() {
	IOProcess(cin, cout);
	return 0;
}
