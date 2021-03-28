#include <iostream>
#include <map>
#include <vector>
#include <exception>
#include <string>
#include <set>
#include <iomanip>
using namespace std;

// –еализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
  set<int> months = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  set<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
  Date() {}
  Date(const int& new_year, const int& new_month, const int& new_day) {
	  if (months.count(new_month) == 0) {
		  throw runtime_error("Month value is invalid: " + to_string(new_month));
	  }
	  if (days.count(new_day) == 0) {
		  throw runtime_error("Day value is invalid: " + to_string(new_day));
	  }
	  year = new_year;
	  month = new_month;
	  day = new_day;
  }



  int GetYear() const {
	  return year;
  }

  int GetMonth() const {
	  return month;
  }

  int GetDay() const {
	  return day;
  }

private:
  int year;
  int month;
  int day;
};

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << '-'
		   << setw(2) << setfill('0') << date.GetMonth() << '-'
		   << setw(2) << setfill('0') << date.GetDay();
	return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
	  date_to_event[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
	  if (date_to_event.count(date) > 0) {
		  if (date_to_event[date].count(event) > 0) {
			  date_to_event[date].erase(event);
			  cout << "Deleted successfully" << endl;
			  return true;
		  } else {
			  cout << "Event not found" << endl;
			  return false;
		  }
	  } else {
		  cout << "Event not found" << endl;
		  return false;
	  }
  }

  int DeleteDate(const Date& date) {
	  const int n = date_to_event[date].size();
	  date_to_event.erase(date);
	  cout << "Deleted " << n << " events" << endl;
	  return n;
  }

  void Find(const Date& date) const {
	  if (date_to_event.count(date) > 0) {
		  for (auto& i : date_to_event.at(date)) {
			  cout << i << endl;
		  }
	  }
  }

  void Print() const {
	  for (const auto& item : date_to_event) {
		  for (const auto& s : item.second) {
			  cout << item.first << " " << s << endl;
		  }
	  }
	  //return date_to_event;
  }

private:
  map<Date, vector<string>> date_to_event;
};

bool operator==(const Date& lhs, const Date& rhs) {
	return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() < rhs.GetYear()) {
		return true;
	} else if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() < rhs.GetMonth()) {
			return true;
		} else if (lhs.GetMonth() == rhs.GetMonth()) {
			if (lhs.GetDay() < rhs.GetDay()) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

istream& operator>>(istream& stream, Date& date) {
	int year, month, day, i;
	char delim1, delim2;
	if (stream >> year >> delim1 >> month >> delim2 >> day && stream.eof() && delim1 == '-' && delim2 == '-') {
		date = Date(year, month, day);
	} else {
		throw invalid_argument("Wrong date format: ");
	}
	return stream;
}
//
int main() {
  Database db;
  string command, operation;
  while (getline(cin, command)) {
    // —читайте команды с потока ввода и обработайте каждую
	  if (command.size() > 0) {
	  stringstream s1(command);
	  Date date;
	  string event, date_string;
	  s1 >> operation;
	  if (operation == "Print") {
		  db.Print();
	  } else if (operation == "Add" || operation == "Find" || operation == "Del") {
		  s1 >> date_string;
		  stringstream s2(date_string);
		  try {
			  s2 >> date;
		  } catch (invalid_argument& ex){
			  cout << ex.what() << date_string << endl;
			  return 1;
		  } catch (runtime_error& ex) {
			  cout << ex.what() << endl;
			  return 1;
		  }
		  if (operation == "Add") {
			  s1 >> event;
			  db.AddEvent(date, event);
		  } else if (operation == "Find") {
			  db.Find(date);
		  } else if (operation == "Del") {
			  if (s1 >> event) {
				  db.DeleteEvent(date, event);
			  } else {
			  	  db.DeleteDate(date);
			  }
		  }
	  }  else {
		  cout << "Unknown command: " << operation << endl;
	  }
	  }
  }

  return 0;
}
