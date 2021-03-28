#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
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
	  string GetFullNameWithHistory(int year) {
		 vector<string> names = {}, surnames = {};
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
	  // приватные поля
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}



