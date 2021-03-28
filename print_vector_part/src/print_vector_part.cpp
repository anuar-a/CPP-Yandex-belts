#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	auto it = find_if(numbers.begin(), numbers.end(), [](const int& a) {return a < 0;});
	if (it == numbers.end()) {
		auto end_it = numbers.end();
		while (end_it != numbers.begin()) {
			--end_it;
			cout << *end_it << " ";
		}
	} else {
		while (it != numbers.begin()) {
					--it;
					cout << *it << " ";
				}
	}
}

int main() {
	PrintVectorPart({6, 1, 8, -5, 4});
	cout << endl;
	PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
	cout << endl;
	PrintVectorPart({6, 1, 8, 5, 4});
  	cout << endl;
    return 0;
}
