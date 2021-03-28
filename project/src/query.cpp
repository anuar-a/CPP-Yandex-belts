#include "query.h"

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
