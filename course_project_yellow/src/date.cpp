#include "date.h"
#include <vector>

Date::Date(const int& new_year, const int& new_month, const int& new_day) {
	  if (new_month < 0 || new_month > 12) {
		  throw runtime_error("Month value is invalid: " + to_string(new_month));
	  }
	  if (new_day < 0 || new_day > 31) {
		  throw runtime_error("Day value is invalid: " + to_string(new_day));
	  }
	  year = new_year;
	  month = new_month;
	  day = new_day;
}

int Date::GetYear() const {
	return year;
}

int Date::GetMonth() const {
	return month;
}

int Date::GetDay() const {
	return day;
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << '-'
		   << setw(2) << setfill('0') << date.GetMonth() << '-'
		   << setw(2) << setfill('0') << date.GetDay();
	return stream;
}

bool operator==(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} == vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} != vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator<(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} < vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator<=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <= vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} > vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >= vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};

}

Date ParseDate(istream& is) {
	int year, month, day, i;
	char delim1, delim2, space;
	//space = is.get();
	if (is >> year >> delim1 >> month >> delim2 >> day && delim1 == '-' && delim2 == '-') {
		Date date = Date(year, month, day);
		return date;
	} else {
		throw invalid_argument("Wrong date format: ");
	}
}
