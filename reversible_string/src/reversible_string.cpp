#include <iostream>
#include <string>
using namespace std;

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(const string& str) {
		s = str;
	}
	string Reverse () {
		string tmp = "";
		for (int i = s.size() - 1; i >= 0; --i) {
			tmp += s[i];
		}
		s = tmp;
		return s;
	}
	string ToString() const {
		return s;
	}
private:
	string s;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
