#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
	string s = "22:01:51";
	throw invalid_argument("sad");
	return s;
    /* ��� ������������ ������������ ���� ���, ����������� ��������� ��������� ���� ������:
       * ���������� ������� ���������� ��������
       * ������ ���������� system_error
       * ������ ������� ���������� � ����������.
    */
}

class TimeServer {
public:
    string GetCurrentTime() {
    	try {
    		last_fetched_time = AskTimeServer();
    	} catch (system_error& se) {
    	}
    	return last_fetched_time;
        /* ���������� ���� �����:
            * ���� AskTimeServer() ������� ��������, �������� ��� � last_fetched_time � �������
            * ���� AskTimeServer() ������� ���������� system_error, ������� ������� ��������
            ���� last_fetched_time
            * ���� AskTimeServer() ������� ������ ����������, ���������� ��� ������.
        */
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // ����� ���������� ������� AskTimeServer, ���������, ��� ��� ��� �������� ���������
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
