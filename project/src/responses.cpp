#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // ���������� ��� �������
  os << r.message;
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // ���������� ��� �������
  os << r.message;
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // ���������� ��� �������
  os << r.message;
  return os;
}
