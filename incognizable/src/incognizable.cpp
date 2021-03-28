#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Incognizabl {
public:
	Incognizabl() {
		data1 = 0;
		data2 = 0;
	}
	Incognizabl(const int& v1, const int& v2) {
		data1 = v1;
		data2 = v2;
	}
private:
	int data1;
	int data2;
};

struct Incognizable {
	int data1;
	int data2;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
