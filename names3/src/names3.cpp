#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class Person {
	public:

	  Person (const string& f_name, const string& l_name, const int& y) {
		  FirstName[y] = f_name;
		  LastName[y] = l_name;
		  birth_year = y;
	  }
	  void ChangeFirstName(int year, const string& first_name) {
		  if (year >= birth_year) {
			  FirstName[year] = first_name;}
	  }
	  void ChangeLastName(int year, const string& last_name) {
		  if (year >= birth_year) {
			  LastName[year] = last_name;}
	  }
	  string GetFullName(int year) const {
		string name = "", surname = "";
		if (year < birth_year) {
			return "No person";
		}
		for (const auto& item : FirstName) {
			if (year < item.first) {
				break;
			}
			name = item.second;
		}
		for (const auto& item : LastName) {
			if (year < item.first) {
				break;
			}
			surname = item.second;
		}
		if (name == "" && surname == "") {
			return "Incognito";
		} else if (name == "" && surname != "") {
			return surname + " with unknown first name";
		} else if (surname == "" && name != "") {
			return name + " with unknown last name";
		} else {
			return name + " " + surname;
		}
	  }
	  string GetFullNameWithHistory(int year) const {
		 vector<string> names = {}, surnames = {};
		 if (year < birth_year) {
			 return "No person";
		 }
		 for (const auto & item : FirstName) {
			 if (year < item.first) {
				 break;
			 }
			 if (names.size() > 0 && names.back() == item.second) {
				 continue;
			 }
			 names.push_back(item.second);
		 }

		 for (const auto & item : LastName) {
			 if (year < item.first) {
				 break;
			 }
			 if (surnames.size() > 0 && surnames.back() == item.second) {
				 continue;
			 }
			 surnames.push_back(item.second);
		 }

		 if (names.size() == 0 && surnames.size() == 0) {
			 return "Incognito";
		 } else if (surnames.size() == 0 && names.size() > 0) {
			 string result = "";
			 result += names.back();
			 names.resize(names.size() - 1);
			 if (names.size() == 1) {
				 result = result + " (" + names[0] + ") with unknown last name";
			 }
			 else if (names.size() > 1) {
				 result += " (";
				 for (int i = names.size() - 1; i > 0; --i) {
					 result = result + names[i] + ", ";
				 }
				 result = result + names[0] + ") with unknown last name";
			 }
			 else {
				 result += " with unknown last name";
			 }
			 return result;
		 } else if (names.size() == 0 && surnames.size() > 0) {
			 string result = "";
			 result += surnames.back();
			 surnames.resize(surnames.size() - 1);
			 if (surnames.size() == 1) {
				 result = result + " (" + surnames[0] + ") with unknown first name";
			 }
			 else if (surnames.size() > 1) {
				 result += " (";
				 for (int i = surnames.size() - 1; i > 0; --i) {
					 result = result + surnames[i] + ", ";
				 }
				 result = result + surnames[0] + ") with unknown first name";
			 }
			 else {
				 result += " with unknown first name";
			 }
			 return result;
		 } else {
			 string result;
			 result += names.back();
			 names.resize(names.size() - 1);
			 if (names.size() == 1) {
				 result = result + " (" + names[0] + ") ";
			 }
			 else if (names.size() > 1) {
				 result += " (";
				 for (int i = names.size() - 1; i > 0; --i) {
					 result = result + names[i] + ", ";
				 }
				 result = result + names[0] + ") ";
			 }
			 else {
				 result += " ";
			 }
			 result += surnames.back();
			 surnames.resize(surnames.size() - 1);
			 if (surnames.size() == 1) {
				 result = result + " (" + surnames[0] + ")";
			 }
			 else if (surnames.size() > 1) {
				 result += " (";
				 for (int i = surnames.size() - 1; i > 0; --i) {
					 result = result + surnames[i] + ", ";
				 }
				 result = result + surnames[0] + ")";
			 }
			 return result;
		 }

	  }

	private:

	  map<int, string> FirstName;
	  map<int, string> LastName;
	  int birth_year;
	  // приватные поля
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}


