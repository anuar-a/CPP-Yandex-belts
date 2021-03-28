#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BusesForStopResponse {
	string message;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	string message;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	string message;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
