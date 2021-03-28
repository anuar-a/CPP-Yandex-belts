#include <iostream>
#include <sstream>
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


    void SetNumerator(const int& new_num) {
    	numerator = new_num;
    	Update(numerator, denominator);
    }

    void SetDenominator(const int& new_denom) {
    	denominator = new_denom;
    	Update(numerator, denominator);
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

ostream& operator<<(ostream& stream, const Rational& rational) {
	stream << rational.Numerator() << '/' << rational.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
	int temp_num, temp_denom;
	char delim;
	if (stream >> temp_num >> delim >> temp_denom) {
		if (delim == '/'&& temp_denom != 0) {
			rational = Rational(temp_num, temp_denom);
		}
	}
	return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("500/-701 100/80");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(500, -701) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(500, -701) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
