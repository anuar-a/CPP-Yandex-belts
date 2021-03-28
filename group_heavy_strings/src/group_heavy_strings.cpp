#include <algorithm>
#include <deque>
#include <map>
#include <string>
#include <vector>

using namespace std;

// ќбъ€вл€ем Group<String> дл€ произвольного типа String
// синонимом vector<String>.
// Ѕлагодар€ этому в качестве возвращаемого значени€
// функции можно указать не малопон€тный вектор векторов,
// а вектор групп Ч vector<Group<String>>.
template <typename String>
using Group = vector<String>;

// ≈щЄ один шаблонный синоним типа
// позвол€ет вместо громоздкого typename String::value_type
// использовать Char<String>
template <typename String>
using Char = typename String::value_type;

template <typename String>
using Key = String;


template <typename String>
Key<String> ComputeStringKey(const String& string) {
  String chars = string;
  sort(begin(chars), end(chars));
  chars.erase(unique(begin(chars), end(chars)), end(chars));
  return chars;
}


template <typename String>
vector<Group<String>> GroupHeavyStrings(vector<String> strings) {
  map<Key<String>, Group<String>> groups_map;
  for (String& string : strings) {
    groups_map[ComputeStringKey(string)].push_back(move(string));
  }
  vector<Group<String>> groups;
  for (auto& [key, group] : groups_map) {
    groups.push_back(move(group));
  }
  return groups;
}
