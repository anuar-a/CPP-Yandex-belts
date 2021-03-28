#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector<int>& v){
	vector<int> tmp;
	for (int i = v.size() - 1; i >= 0; --i){
		tmp.push_back(v[i]);
	}
	v.clear();
	for (auto item:tmp){
		v.push_back(item);
	}
}

int main() {
	vector<int> numbers = {1,6,2,7};
	Reverse(numbers);
	for (auto item: numbers) {
		cout << item;
	}
	return 0;
}
