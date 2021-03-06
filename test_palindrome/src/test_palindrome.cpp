#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& s) {
    for (int i = 0; i < static_cast<int>(s.size()) / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void TestAll() {
	Assert(IsPalindrom("maddam"),"maddam");
	Assert(IsPalindrom("level"),"level");
	Assert(IsPalindrom("wasitacaroracatisaw"),"wasitacaroracatisaw");
	Assert(IsPalindrom(""),"empty");
	Assert(IsPalindrom("a"),"a");
	Assert(IsPalindrom("ma am"),"ma am");
	Assert(IsPalindrom("ma  am"),"ma  am");
	Assert(IsPalindrom(" "),"space");
	Assert(IsPalindrom("m a d a m"),"m a d a m");
	Assert(IsPalindrom(" m a d a m ")," m a d a m ");
	Assert(IsPalindrom("m a d d a m"),"m a d d a m");
	Assert(IsPalindrom(" m a d d a m ")," m a d d a m ");
	Assert(IsPalindrom("m a d  d a m"),"m a d  d a m");
	Assert(IsPalindrom("  m a d d a m  "),"  m a d d a m  ");
	Assert(IsPalindrom("m  a d  d a  m"),"m  a d  d a  m");
	Assert(!IsPalindrom("madas"),"madas");
	Assert(!IsPalindrom("madsm"),"madsm");
	Assert(!IsPalindrom("msdam"),"msdam");
	Assert(!IsPalindrom(" madam")," madam");
	Assert(!IsPalindrom("madam "),"madam ");

}

int main() {
  TestRunner runner;
  runner.RunTest(TestAll, "TestAll");
  return 0;
}
