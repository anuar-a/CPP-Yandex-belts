#include <iostream>
#include <exception>
#include <algorithm>
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

Rational operator/(const Rational& first, const Rational& second) {
	if (second.Numerator() == 0) {
		throw domain_error("Domain error");
	}
	return Rational {first.Numerator() * second.Denominator(),
					 first.Denominator() * second.Numerator()};
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
