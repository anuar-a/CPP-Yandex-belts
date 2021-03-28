#include "database.h"
#include <algorithm>


void Database::Add(const Date& date, const string& event) {
	auto it = data_set[date].insert(event);
	if (it.second) {
		data_vector[date].push_back(event);
	}
}

void Database::Print(ostream& cout) const {
  for (const auto& item : data_vector) {
	  for (const auto& s : item.second) {
		  cout << item.first << " " << s << "\n";
	  }
  }
}

pair<Date, string> Database::Last(const Date& date) const {
	if (date < data_vector.begin()->first || data_vector.empty()) {
		throw invalid_argument("No entries");
	}
	auto it = prev(data_vector.upper_bound(date));
	return make_pair(it->first, *prev(it->second.end()));
}
//
