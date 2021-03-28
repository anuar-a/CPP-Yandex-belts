#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> s;
  for (auto& i : m) {
	  s.insert(i.second);
  }
  return s;
}

