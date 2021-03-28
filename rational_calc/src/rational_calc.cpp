#include <iostream>
#include <exception>
#include <algorithm>
#include <string>
using namespace std;

class Rational {
public:
    Rational() {
    	numerator = 0;
    	denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
    	if (new_denominator == 0) {
    		throw invalid_argument("Invalid argument");
    	}
    	if (new_numerator == 0) {
    		numerator = 0;
    		denominator = 1;
    	} else {
    		Update(new_numerator, new_denominator);
    		if (new_numerator < 0) {
    			if (new_denominator < 0) {
    				numerator *= -1;
    				denominator *= -1;
    			}
    		} else {
    			if (new_denominator < 0) {
    				numerator *= -1;
    				denominator *= -1;
    			}
    		}
    	}
    }

    void Update(const int& new_numerator, const int& new_denominator) {
    	int q = __gcd(abs(new_numerator), abs(new_denominator));
    	numerator = new_numerator / q;
    	denominator = new_denominator / q;
    }

    int Numerator() const {
    	return numerator;
    }

    int Denominator() const {
    	return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& first, const Rational& second) {
	return first.Numerator() == second.Numerator() && first.Denominator() == second.Denominator();
}

Rational operator+(const Rational& first, const Rational& second) {
	return Rational {first.Numerator() * second.Denominator() + second.Numerator() * first.Denominator(),
					 first.Denominator() * second.Denominator()};
}

Rational operator-(const Rational& first, const Rational& second) {
	return Rational {first.Numerator() * second.Denominator() - second.Numerator() * first.Denominator(),
					 first.Denominator() * second.Denominator()};
}

Rational operator*(const Rational& first, const Rational& second) {
	return Rational {first.Numerator() * second.Numerator(),
					 first.Denominator() * second.Denominator()};
}

Rational operator/(const Rational& first, const Rational& second) {
	if (second.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	return Rational {first.Numerator() * second.Denominator(),
					 first.Denominator() * second.Numerator()};
}

ostream& operator<<(ostream& stream, const Rational& rational) {
	stream << rational.Numerator() << '/' << rational.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
	int temp_num, temp_denom;
	char delim;
	if (stream >> temp_num) {
		stream >> delim;
		stream >> temp_denom;
		if (delim == '/') {
			rational = Rational(temp_num, temp_denom);
		}
	}
	return stream;
}

int main() {
	Rational r1, r2;
	string op;
	try {
		cin >> r1;
		cin >> op;
		cin >> r2;
	} catch (invalid_argument& ex) {
		cout << ex.what() << endl;
		return 3;
	}
	if (op == "/") {
		try {
			r1 / r2;
			cout << r1 / r2 << endl;
			return 2;
		} catch (domain_error& ex) {
			cout << ex.what() << endl;
			return 4;
		}
	} else if (op == "+") {
		cout << r1 + r2 << endl;
	} else if (op == "-") {
		cout << r1 - r2 << endl;
	} else if (op == "*") {
		cout << r1 * r2 << endl;
	}
    return 0;
}
