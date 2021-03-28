#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <exception>
#include <cmath>

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

int GetDistinctRealRootCount(double A, double B, double C) {
  // ¬ы можете вставл€ть сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и лов€т некорректный
	  double D = B * B - 4 * A * C;

	  // если A равно нулю, то уравнение линейное: Bx + C = 0
	  if (A == 0) {

	    // Bx = -C => x = -C / B
	    if (B != 0) {
	      return 1;
	    } else {
	    	return 0;
	    }
	    // если B равно нулю, корней нет

	  } else if (D == 0) {  // случай с нулевым дискриминантом

	    // корень ровно один
	    return 1;

	  } else if (D > 0) {  // в случае с положительным дискриминантом корн€ два
	    return 2;

	  } else {
		  return 0;
	  }
}

void TestMain() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "B is 0");
	AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, "B is 1");
	AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1, "D is 0");
	AssertEqual(GetDistinctRealRootCount(2, 3, 1), 2, "D > 0");
	AssertEqual(GetDistinctRealRootCount(3, 2, 1), 0, "D < 0");
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestMain, "TestMain");
  cout << "PASS" << endl;
  return 0;
}
