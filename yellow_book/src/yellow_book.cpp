#include "yellow_pages.h"

#include <algorithm>
#include <tuple>

namespace YellowPages {

  Company Merge(const Signals& signals, const Providers&) {
    // ������� ������������ ����������: ���� ��� ������ �� ������ ������� �������, ����� �� ��������� ����������
    return signals.empty() ? Company() : signals[0].company();
  }

}
