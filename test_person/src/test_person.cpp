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

void TestMainSimple() {
	Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    AssertEqual(person.GetFullName(1900), "Incognito", "1900 Incognito");
    AssertEqual(person.GetFullName(1965), "Polina with unknown last name", "1965 Polina no l/n");
    AssertEqual(person.GetFullName(1990), "Polina Sergeeva", "1990 Polina Sergeeva");

    person.ChangeFirstName(1970, "Appolinaria");
    AssertEqual(person.GetFullName(1969), "Polina Sergeeva", "1969 Polina Sergeeva");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva", "1970 Appolinaria Sergeeva");

    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1969), "Polina Volkova", "1969 Polina Volkova");
    AssertEqual(person.GetFullName(1970), "Appolinaria Volkova", "1970 Appolinaria Volkova");
}

void TestMainHard() {
	Person person;
	person.ChangeLastName(3, "3_2nd");
	person.ChangeLastName(6, "6_2nd");

	AssertEqual(person.GetFullName(3), "3_2nd with unknown first name", "3 3_2nd with unknown first name");
	AssertEqual(person.GetFullName(4), "3_2nd with unknown first name", "4 3_2nd with unknown first name");
	AssertEqual(person.GetFullName(5), "3_2nd with unknown first name", "5 3_2nd with unknown first name");
	AssertEqual(person.GetFullName(6), "6_2nd with unknown first name", "6 6_2nd with unknown first name");

	person.ChangeFirstName(-1, "-1_1st");
	person.ChangeFirstName(2, "2_1st");

	AssertEqual(person.GetFullName(-1), "-1_1st with unknown last name", "-1 -1_1st with unknown last name");
	AssertEqual(person.GetFullName(0), "-1_1st with unknown last name", "0 -1_1st with unknown last name");
	AssertEqual(person.GetFullName(1), "-1_1st with unknown last name", "1 -1_1st with unknown last name");
	AssertEqual(person.GetFullName(2), "2_1st with unknown last name", "2 2_1st with unknown last name");
	AssertEqual(person.GetFullName(3), "2_1st 3_2nd", "3 2_1st 3_2nd");
	AssertEqual(person.GetFullName(6), "2_1st 6_2nd", "6 2_1st 6_2nd");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestMainSimple, "TestMainSimple");
  runner.RunTest(TestMainHard, "TestMainHard");
  return 0;
}
