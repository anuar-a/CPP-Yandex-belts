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

vector<int> Reversed(const vector<int>& v){
	vector<int> copy_v = v;
	Reverse(copy_v);
	return copy_v;
}

int main() {
	vector<int> numbers = {1,6,2,7};
	numbers = Reversed(numbers);
	for (auto item: numbers) {
		cout << item;
	}
	return 0;
}
