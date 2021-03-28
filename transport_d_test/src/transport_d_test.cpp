#define _USE_MATH_DEFINES

#include "json.h"
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
	Stop(double long latitude, double long longitude):lat(latitude), lng(longitude) {
	}
};

struct Bus {
	vector<string> stops;
	Bus() = default;
	Bus(vector<string> stops_):stops(stops_) {}
};

class TransportManager {
public:
	void AddStop(string& name, double long lat, double long lng) {
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

	double long CalculateRouteLengthByCoordinates(string& name) {
		double long route_length = 0;
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
	double long CalculateCurvature(string& name) {
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
			os << endl;
		}
	}

	string PrintJsonStop(string name, uint64_t id) {
		stringstream os;
		os << '{';
		if (!StopExists(name)) {
			os << "\"request_id\": " << id << ','
			   << "\"error_message\": \"not found\"}";
		} else if (stops_data[name].buses.size() == 0){
			os << "\"buses\": []" << ','
			   << "\"request_id\": " << id << "}";
		} else if (stops_data[name].buses.size() > 0){
			int counter = 1;
			os << "\"buses\": [";
			auto size_ = stops_data[name].buses.size();
			for (auto& bus : stops_data[name].buses) {
				if (counter != size_) {
					os << "\"" << bus << "\",";
				} else {
					os << "\"" << bus << "\"],";
				}
				counter += 1;
			}
			os << "\"request_id\": " << id << "}";
			//os << endl;
		}
		return os.str();
	}

	string PrintJsonBus(string name, uint64_t id) {
		stringstream os;
		os << '{';
		//cout << "in" << name << endl;
		//cout << "in" << id << endl;
		if (BusExists(name)) {
			os << "\"route_length\": "  << CalculateRouteLengthByRoads(name) << ','
			   << "\"request_id\": " << id << ','
			   << fixed << setprecision(6) << "\"curvature\": " << CalculateCurvature(name) << ','
			   << "\"stop_count\": " << GetNumOfStops(name) << ','
			   << "\"unique_stop_count\": " << GetNumOfUniqueStops(name) << '}';
		} else {
			os << "\"request_id\": " << id << ','
			   << "\"error_message\": \"not found\"}";
		}
		return os.str();
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

int main() {
	TransportManager tm;
	auto doc = Json::Load(cin);
	auto& root = doc.GetRoot();
	auto& m = root.AsMap();
	auto& base_requests = m.at("base_requests").AsArray();
	auto& stat_requests = m.at("stat_requests").AsArray();
	cout << base_requests.size() << endl;
	cout << stat_requests.size() << endl;
	return 0;
}
