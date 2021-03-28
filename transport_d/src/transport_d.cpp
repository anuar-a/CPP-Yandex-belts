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

	string PrintJsonStop(string name, int id) {
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

	string PrintJsonBus(string name, int id) {
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

void IOProcess (istream& is, ostream& os) {
	TransportManager tm;
	int n;
	string command;
	is >> n;
	for (int i = 0; i < n; ++i) {
		is >> command;
		if (command == "Stop") {
			string name;
			double long lat, lng;
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

void IOProcessJson (istream& is, ostream& os){
	is.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	os.precision(6);
	TransportManager tm;
	auto doc = Json::Load(is);
	auto& root = doc.GetRoot();
	auto& m = root.AsMap();
	auto& base_requests = m.at("base_requests").AsArray();
	auto& stat_requests = m.at("stat_requests").AsArray();
	//cout << base_requests.size() << endl;
	//cout << stat_requests.size() << endl;
	for (auto& request:base_requests) {
		auto& req_map = request.AsMap();
		if (req_map.at("type").AsString() == "Stop") {
			string stop_name = req_map.at("name").AsString();
			double latitude = req_map.at("latitude").AsNumber();
			double longitude = req_map.at("longitude").AsNumber();
			//cout << "Stop " << stop_name << endl;
			auto& road_distances = req_map.at("road_distances").AsMap();
			tm.AddStop(stop_name, latitude, longitude);
			for (auto item : road_distances) {
				auto stop_to = item.first;
				auto distance = item.second.AsNumber();
				tm.AddDistancesToStops(stop_name, stop_to, distance);
			}
		} else if (req_map.at("type").AsString() == "Bus") {
			string bus_name = req_map.at("name").AsString();
			auto stops = req_map.at("stops").AsArray();
			bool is_roundtrip = req_map.at("is_roundtrip").AsBool();
			vector<string> stops_string;
			//cout << "Bus " << bus_name << endl;
			for (auto& stop : stops) {
				stops_string.push_back(stop.AsString());
			}
			if (!is_roundtrip) {
				stack<string> s;
				for (auto& stop : stops_string) {
					s.push(stop);
				}
				s.pop();
				while(!s.empty()) {
					stops_string.push_back(s.top());
					s.pop();
				}
			}
			tm.AddBus(bus_name, stops_string);
		}
	}
	string answer = "[";
	int counter = 1;
	for (auto& request:stat_requests) {
		auto& req_map = request.AsMap();
		int id;
		id = req_map.at("id").AsNumber();
		if (req_map.at("type").AsString() == "Stop") {
			auto stop_name = req_map.at("name").AsString();
			answer += tm.PrintJsonStop(stop_name, id);
		} else if (req_map.at("type").AsString() == "Bus") {
			auto bus_name = req_map.at("name").AsString();
			//cout << id << endl;
			//cout << bus_name << endl;
			answer += tm.PrintJsonBus(bus_name, id);
		}
		if (counter != stat_requests.size()) {
			answer += ",";
		}
		counter += 1;
	}
	answer += ']';
	os << answer;


}

int main() {
	//IOProcess(cin, cout);
	IOProcessJson(cin, cout);
	return 0;
}
