#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> result;
	auto it1 = s.begin();
	auto it2 = s.begin();
	while (it2 != s.end()) {
		it2 = find(it1, s.end(), ' ');
		string st(it1, it2);
		result.push_back(st);
		if (it2 != s.end()) {
			++it2;
		}
		it1 = it2;
	}
	return result;
}

int main() {
    /*string s = "CSharp Cyx Java Python";
    auto it1 = find(s.begin(), s.end(), ' ');
    cout << *--it1 << endl;
    ++it1;
    auto it2 = find(++it1, s.end(), ' ');
    cout << *--it2 << endl;
    ++it2;
    auto it3 = find(++it2, s.end(), ' ');
    cout << *--it3 << endl;*/
	string s = "CSharp Cyx Java Python";
    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
      if (it != begin(words)) {
        cout << "/";
      }
      cout << *it;
    }
    cout << endl;
    return 0;
  }
