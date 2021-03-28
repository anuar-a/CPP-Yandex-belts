#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>
using namespace std;

enum class Command{
	ComputeIncome,
	Earn,
	PayTax
};

class Date {
public:
	Date() = default;

	Date(int year, int month, int day):year_(year), month_(month), day_(day) {
	}

	int GetYear() const {
		return year_;
	}

	int GetMonth() const {
		return month_;
	}

	int GetDay() const {
		return day_;
	}

	time_t AsTimestamp() const {
	  std::tm t;
	  t.tm_sec   = 0;
	  t.tm_min   = 0;
	  t.tm_hour  = 0;
	  t.tm_mday  = day_;
	  t.tm_mon   = month_ - 1;
	  t.tm_year  = year_ - 1900;
	  t.tm_isdst = 0;
	  return mktime(&t);
	}

private:
	int year_;
	int month_;
	int day_;
};

istream& operator>> (istream& is, Date& date) {

}
ostream& operator<< (ostream& os, Date& date) {
	os << date.GetYear() << '-' << date.GetMonth() << '-' << date.GetDay();
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
	int year, month, day;
	char delim1, delim2, space;
	//space = is.get();
	if (is >> year >> delim1 >> month >> delim2 >> day && delim1 == '-' && delim2 == '-') {
		Date date(year, month, day);
		return date;
	} else {
		throw invalid_argument("Wrong date format: ");
	}
}

int ComputeDaysDiff(const Date& date_to, const Date& date_from) {
  const time_t timestamp_to = date_to.AsTimestamp();
  const time_t timestamp_from = date_from.AsTimestamp();
  static const int SECONDS_IN_DAY = 60 * 60 * 24;
  return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
}

class BudgetManager {
public:
	BudgetManager():data(DAYS_SPAN) {
	}

	void ComputeIncome(Date& from, Date& to) {
		double income = 0;
		int from_index = GetIndex(from);
		int to_index = GetIndex(to);
		for (int i = from_index; i <= to_index; ++i) {
			income += data[i];
		}
		std::cout.precision(25);
		cout << income << endl;
	}

	void Earn(Date& from, Date& to, int value) {
		double daily_value = value / (ComputeDaysDiff(to, from) + 1.0);
		int from_index = GetIndex(from);
		int to_index = GetIndex(to);
		for (int i = from_index; i <= to_index; ++i) {
			data[i] += daily_value;
		}
	}

	void PayTax(Date& from, Date& to) {
		int from_index = GetIndex(from);
		int to_index = GetIndex(to);
		for (int i = from_index; i <= to_index; ++i) {
			data[i] *= 0.87;
		}
	}

	static const int DAYS_SPAN = 36525;
private:
	vector<double> data;
	int GetIndex(Date& date) {
		return ComputeDaysDiff(date, {2000, 1, 1});
	}
};

void ReadInput(istream& is) {
	BudgetManager bm;
	int count, value;
	string command;
	//Date from, to;
	is >> count;
	for (int i = 0; i < count; ++i) {
		is >> command;
		auto from = ParseDate(is);
		auto to = ParseDate(is);
		if (command == "ComputeIncome") {
			bm.ComputeIncome(from, to);
		} else if (command == "Earn") {
			is >> value;
			bm.Earn(from, to, value);
		} else if (command == "PayTax") {
			bm.PayTax(from, to);
		}
	}
}

int main() {
	ReadInput(cin);
	return 0;
}
