#include "phone_number.h"
#include <iostream>
#include <sstream>
#include <exception>

using namespace std;

  PhoneNumber::PhoneNumber(const string &international_number) {
	  stringstream s(international_number);
	  char plus;
	  string country, city, local;

	  if (s >> plus && getline(s, country, '-') && getline(s, city, '-') && getline(s, local)) {
		  if (plus == '+') {
			  country_code_ = country;
			  city_code_ = city;
			  local_number_ = local;
		  } else {
			  throw invalid_argument("Invalid format");
		  }
	  } else {
		  throw invalid_argument("Invalid format");
	  }
  }
  string PhoneNumber::GetCountryCode() const {
	  return country_code_;
  }

  string PhoneNumber::GetCityCode() const {
	  return city_code_;
  }

  string PhoneNumber::GetLocalNumber() const {
	  return local_number_;
  }

  string PhoneNumber::GetInternationalNumber() const {
	  return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
  }

