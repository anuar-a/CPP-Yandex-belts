#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

const double pi = 3.14;

class Figure{
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Triangle:public Figure{
public:
	Triangle(const string& name, const double& a, const double& b, const double& c):name_(name), a_(a), b_(b), c_(c){
	}

	string Name() const override {
		return name_;
	}

	double Perimeter() const override {
		return a_ + b_ + c_;
	}

	double Area() const override {
		double s = (a_ + b_ + c_) / 2;
		return sqrt(s * (s - a_) * (s - b_) * (s - c_));
	}
private:
	const string name_;
	const double a_;
	const double b_;
	const double c_;
};

class Rect:public Figure{
public:
	Rect(const string& name, const double& w, const double& h):name_(name), w_(w), h_(h){
	}

	string Name() const override {
		return name_;
	}

	double Perimeter() const override {
		return 2 * (w_ + h_);
	}

	double Area() const override {
		return w_ * h_;
	}
private:
	const string name_;
	const double w_;
	const double h_;
};

class Circle:public Figure{
public:
	Circle(const string& name, const double& r):name_(name), r_(r) {

	}
	string Name() const override {
		return name_;
	}

	double Perimeter() const override {
		return 2 * pi * r_;
	}

	double Area() const override {
		return pi * r_ * r_;
	}
private:
	const string name_;
	const double r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
	string name;
	is >> name;
	if (name == "RECT") {
		double w, h;
		is >> w >> h;
		shared_ptr<Rect> rect = make_shared<Rect> (name, w, h);
		return rect;
	} else if (name == "TRIANGLE") {
		double a, b, c;
		is >> a >> b >> c;
		shared_ptr<Triangle> triangle = make_shared<Triangle> (name, a, b, c);
		return triangle;
	} else if (name == "CIRCLE") {
		double r;
		is >> r;
		shared_ptr<Circle> circle = make_shared<Circle> (name, r);
		return circle;
	}
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
