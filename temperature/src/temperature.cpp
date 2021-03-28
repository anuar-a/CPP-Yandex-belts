#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v) {
	for (auto s : v) {
		cout << s << " ";
	}
}

int Average (const vector<int>& v) {
	long long int sum = 0;
	for (auto i : v) {
		sum += i;
	}
	return sum/static_cast<long long int>(v.size());
}

int main() {
	int n, average, count = 0;
	cin >> n;
	vector<int> numbers(n), answer;
	for (int& i : numbers){
		cin >> i;
	}
	average = Average(numbers);
	for (size_t j = 0; j + 1 <= numbers.size(); ++j) {
		if (numbers[j] > average) {
			count += 1;
			answer.push_back(j);
		}
	}
	cout << count << endl;
	PrintVector(answer);
	return 0;
}
//
