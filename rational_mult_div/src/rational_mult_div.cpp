#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Rational {
public:
    Rational() {
    	numerator = 0;
    	denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
    	if (new_numerator == 0) {
    		numerator = 0;
    		denominator = 1;
    	} else {
    		int q = __gcd(abs(new_numerator), abs(new_denominator));
    		numerator = new_numerator / q;
    		denominator = new_denominator / q;
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
	return Rational {first.Numerator() * second.Denominator(),
					 first.Denominator() * second.Numerator()};
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
