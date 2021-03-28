#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Person {
	public:

	  void ChangeFirstName(int year, const string& first_name) {
		FirstName[year] = first_name;
	  }
	  void ChangeLastName(int year, const string& last_name) {
		LastName[year] = last_name;
	  }
	  string GetFullName(int year) {
		string name = "", surname = "";
		auto it_name = FirstName.lower_bound(year);
		if (it_name == FirstName.end()) {
			if (FirstName.empty()) {
				name = "";
			} else {
				name = prev(it_name)->second;
			}
		} else if (it_name == FirstName.begin()) {
			if (it_name->first == year) {
				name = it_name->second;
			} else {
				name = "";
			}
		} else {
			if (it_name->first == year) {
				name = it_name->second;
			} else {
				name = prev(it_name)->second;
			}
		}
		auto it_surname = LastName.lower_bound(year);
		if (it_surname == LastName.end()) {
			if (LastName.empty()) {
				surname = "";
			} else {
				surname = prev(it_surname)->second;
			}
		} else if (it_surname == LastName.begin()) {
			if (it_surname->first == year) {
				surname = it_surname->second;
			} else {
				surname = "";
			}
		} else {
			if (it_surname->first == year) {
				surname = it_surname->second;
			} else {
				surname = prev(it_surname)->second;
			}		}
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
	  void Print() {
		  for (auto& i : LastName) {
			  cout << i.first << i.second << endl;
		  }
	  }
	private:

	  map<int, string> FirstName;
	  map<int, string> LastName;
	  // приватные поля
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
