#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	if ((range_end - range_begin) < 2) {
		return;
	}
	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	auto mid1 = elements.begin() + (range_end - range_begin)/3;
    auto mid2 = elements.begin() + (range_end - range_begin)*2/3;
    MergeSort(elements.begin(), mid1);
    MergeSort(mid1, mid2);
    MergeSort(mid2, elements.end());
	vector<typename RandomIt::value_type> temp;
	merge(elements.begin(), mid1, mid1, mid2, back_inserter(temp));
	merge(temp.begin(), temp.end(), mid2, elements.end(), range_begin);
}

int main() {
	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    /*auto const mid1 = (v.end() - v.begin())/3;
    auto const mid2 = mid1 * 2;
    cout << mid1 << endl;
    cout << mid2 << endl;
    vector<int> v1(v.begin(), v.begin() + mid1);
    vector<int> v2(v.begin() + mid1, v.begin() + mid2);
    vector<int> v3(v.begin() + mid2, v.end());

    for (auto i : v1) {
    	cout << i << " ";
    }
    cout << endl;
    for (auto i : v2) {
    	cout << i << " ";
    }
    cout << endl;
	for (auto i : v3) {
		cout << i << " ";
	}*/
    MergeSort(begin(v), end(v));
    for (int x : v) {
    	cout << x << " ";
    }
    cout << endl;
    return 0;
}
