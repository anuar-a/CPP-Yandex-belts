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

	person.ChangeLastName(3, "3_2nd");
	person.ChangeLastName(6, "6_2nd");

	for (int year : {3, 4, 5, 6}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(-1, "-1_1st");
	person.ChangeFirstName(2, "2_1st");

	for (int year : {-1, 0, 1, 2, 3, 6}) {
		cout << person.GetFullName(year) << endl;
	}
  return 0;
}
