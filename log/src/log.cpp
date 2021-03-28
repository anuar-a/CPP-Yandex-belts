#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) {
	  log_line = value;
  }

  void SetLogFile(bool value) {
	  log_file= value;
  }

  bool GetLogLine() {
	  return log_line;
  }

  bool GetLogFile() {
	  return log_file;
  }

  void Log(const string& message) {
	  os << message;
  }
private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

#define LOG(logger, message) {													\
	ostringstream oss;															\
	if (logger.GetLogLine() == true && logger.GetLogFile() == true) {   		\
		oss << __FILE__ << ":" << __LINE__ << " " << message << "\n"; 			\
		logger.Log(oss.str()); 													\
	} else if (logger.GetLogLine() == true) {    								\
		oss << "Line" << " " << __LINE__ << " " << message << "\n"; 			\
		logger.Log(oss.str()); 													\
	} else if (logger.GetLogFile() == true) {    								\
		oss << __FILE__ << " " << message << "\n"; 								\
		logger.Log(oss.str()); 													\
	} else {    																\
		oss << message << "\n"; 												\
		logger.Log(oss.str()); 													\
	}																			\
}

void TestLog() {
/* ��� ��������� ����-������ � ���� ������ ��� ����� ����������� ����������
 * ������ ����� � ��������� �������� (��. ���������� expected ����). ����
 * �� ��������� �����-�� ��� ���� ������� TestLog, �� ��� ������ ����� ��������,
 * � ��� ���� �������� ������. ��� ��������.
 *
 * ����� ����� ��������, �� ���������� ����������� ������ #line
 * (http://en.cppreference.com/w/cpp/preprocessor/line), ������� ���������
 * �������������� ����� ������, � ����� ��� �����. ��������� ���, ������
 * ����� ������ ������� TestLog ����� ����������� ���������� �� ����, �����
 * ��� �� ��������� ����� ���*/
#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLog);
}
