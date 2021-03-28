#include "test_runner.h"

using namespace std;

template <typename T>
class Table {
public:
	Table(const size_t& rows, const size_t& columns):r(rows), c(columns) {
		Resize(rows, columns);
	}

	void Resize (const size_t& rows, const size_t& columns) {
		r = rows;
		c = columns;
		data.resize(rows);
		for (auto& item : data) {
			item.resize(columns);
		}
	}

	pair<size_t, size_t> Size () const {
		if (r * c == 0) {
			return make_pair(0, 0);
		}
		return make_pair(r, c);
	}

	vector<T>& operator[](const size_t& i) {
		return data[i];
	}

	const vector<T>& operator[](const size_t& i) const{
		return data[i];
	}

private:
	vector<vector<T>> data;
	int r, c;
};



void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  cout << t[1][1] << endl;
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
