#pragma once

#include <map>
#include <sstream>
#include "responses.h"

using namespace std;

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops);

  BusesForStopResponse GetBusesForStop(const string& stop) const;

  StopsForBusResponse GetStopsForBus(const string& bus) const;

  AllBusesResponse GetAllBuses() const;

private:
  map<string, vector<string>> bus_to_stop, stop_to_bus;
};
