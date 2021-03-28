#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
	for (auto& stop : stops) {
		bus_to_stop[bus].push_back(stop);
		stop_to_bus[stop].push_back(bus);
	}
  }

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
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

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
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
