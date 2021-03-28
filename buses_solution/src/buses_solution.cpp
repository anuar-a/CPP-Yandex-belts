#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
	int n = 0;
	string command;
	is >> command;

	if (command == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		is >> n;
		q.stops.resize(n);
		for (auto& item : q.stops) {
			is >> item;
		}
	} else if (command == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
	    is >> q.stop;
	} else if (command == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
	    is >> q.bus;
	} else if (command == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
  return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
  string message;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  os << r.message;
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
  string message;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  os << r.message;
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
  string message;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  os << r.message;
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
	for (auto& stop : stops) {
		bus_to_stop[bus].push_back(stop);
		stop_to_bus[stop].push_back(bus);
	}
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
	  BusesForStopResponse response;
	  stringstream s;
	  if (stop_to_bus.count(stop) == 0) {
					s << "No stop";
				} else {
					for (const auto& i : stop_to_bus.at(stop)) {
						s << i << " ";
					}
				}
	  response.message = s.str();
	  return response;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
	  StopsForBusResponse response;
	  stringstream s;
	  if (bus_to_stop.count(bus) == 0) {
	  				s << "No bus";
	  			} else {
	  				for (const auto& item : bus_to_stop.at(bus)) {
	  					s << "Stop " << item << ": ";
	  					if (stop_to_bus.at(item).size() == 1 && stop_to_bus.at(item)[0] == bus) {
	  						s << "no interchange" << endl;
	  					} else {
	  						for (const auto& each : stop_to_bus.at(item)) {
	  							if (each != bus) {
	  								s << each << " ";
	  							}
	  						}
	  						s << endl;
	  					}
	  				}
	  			}
	  response.message = s.str();
	  return response;
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
	AllBusesResponse response;
	stringstream s;
	if (bus_to_stop.size() == 0) {
					s << "No buses";
				} else {
					for (const auto& each : bus_to_stop) {
						s << "Bus " << each.first << ": ";
						for (const auto& every : bus_to_stop.at(each.first)) {
							s << every << " ";
						}
						s << endl;
					}
				}
    response.message = s.str();
    return response;
  }
private:
  map<string, vector<string>> bus_to_stop, stop_to_bus;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
