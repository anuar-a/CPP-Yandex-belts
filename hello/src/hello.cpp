//============================================================================
// Name        : hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n = 5;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += i;
	}
	cout << sum;
	return 0;
}
