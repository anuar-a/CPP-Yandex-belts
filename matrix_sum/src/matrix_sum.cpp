#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;

class Matrix {
public:

	// Реализуйте здесь
	// * класс Matrix
	// * оператор ввода для класса Matrix из потока istream
	// * оператор вывода класса Matrix в поток ostream
	// * оператор проверки на равенство двух объектов класса Matrix
	// * оператор сложения двух объектов класса Matrix

	Matrix() {
		cols = 0;
		rows = 0;
	}

	Matrix(int num_rows, int num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(int new_num_rows, int new_num_cols) {
		if (new_num_rows < 0 || new_num_cols < 0) {
			throw out_of_range("");
		}
		if (new_num_rows == 0 || new_num_cols == 0) {
			new_num_rows = 0;
			new_num_cols = 0;
		}
		cols = new_num_cols;
		rows = new_num_rows;
		values.resize(rows);
		for(auto& row : values) {
			row.assign(cols, 0);
		}
	}

	int& At(const int& rows_i, const int& cols_i) {
		return values.at(rows_i).at(cols_i);
	}

	int At(const int& rows_i, const int& cols_i) const {
		return values.at(rows_i).at(cols_i);
	}

	int GetNumRows() const {
		return rows;
	}

	int GetNumColumns() const {
		return cols;
	}
private:
	int cols, rows;
	vector<vector<int>> values;
};

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows()) {
		return false;
	}
	for (int i = 0; i < lhs.GetNumRows(); ++i) {
		for (int j = 0; j < lhs.GetNumColumns(); ++j) {
			if (lhs.At(i, j) != rhs.At(i, j)) {
				return false;
			}
		}
	}
	return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows()) {
		throw invalid_argument("");
	}
	Matrix new_matrix(lhs.GetNumRows(), lhs.GetNumColumns());
	for (int i = 0; i < lhs.GetNumRows(); ++i) {
			for (int j = 0; j < lhs.GetNumColumns(); ++j) {
				new_matrix.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
			}
		}
	return new_matrix;
}

ostream& operator<<(ostream& stream, const Matrix& matrix) {
	stream << matrix.GetNumRows() << " ";
	stream << matrix.GetNumColumns() << endl;
	for (int i = 0; i < matrix.GetNumRows(); ++i) {
		for (int j = 0; j < matrix.GetNumColumns(); ++j) {
			if (j > 0) {
				stream << " ";
			}
			stream << matrix.At(i, j);
		}
		stream << endl;
	}
	return stream;
}

istream& operator>>(istream& stream, Matrix& matrix) {
	int rows, cols;
	stream >> rows;
	stream >> cols;
	matrix.Reset(rows, cols);
	for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				stream >> matrix.At(i, j);
			}
		}
	return stream;
}
//
int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two ;
  cout << one + two << endl;
  return 0;
}

