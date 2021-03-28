#pragma once

#include "date.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <memory>

using namespace std;

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
  void Add(const Date& date, const string& event);

  template <typename Predicate>
  int RemoveIf(const Predicate& predicate) {
  	int n = 0;
  	map<Date, vector<string>::iterator> del_it;
  	for (auto& item : data_vector) {
  		auto it = stable_partition(data_vector[item.first].begin(), data_vector[item.first].end(), [&, date=item.first](const string& event){return predicate(date, event);});
  		del_it[item.first] = it;
  		n += it - data_vector[item.first].begin();
  	}

  	for (auto& item : del_it) {
		data_vector[item.first].erase(data_vector[item.first].begin(), item.second);

		data_set[item.first] = set<string>(data_vector[item.first].begin(), data_vector[item.first].end());
		if (data_vector[item.first].empty()) {
			data_vector.erase(item.first);
			data_set.erase(item.first);
		}
  	}
  	return n;
  }

  template <typename Predicate>
  vector<pair<Date, string>> FindIf(const Predicate& predicate) const {
      vector<pair<Date, string>> result;
      for (const auto& item : data_vector) {
      	  for (const auto& s : item.second) {
      		  if (predicate(item.first, s)) {
      			  result.push_back(make_pair(item.first, s));
      		  }
      	  }
        }
      return result;
  }

  void Print(ostream& cout) const;
  pair<Date, string> Last(const Date& date) const;

private:
  map<Date, vector<string>> data_vector;
  map<Date, set<string>> data_set;
};
