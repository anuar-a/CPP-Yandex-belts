#pragma once

#include <cstdlib>
#include <iostream>
using namespace std;

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector():data_(nullptr), end_(nullptr), capacity_(nullptr) {
  }

  explicit SimpleVector(size_t size) {
	  data_ = new T[size];
	  end_ = data_ + size;
	  capacity_ = data_ + size;
	  new_ = false;
  }
  ~SimpleVector() {
	  if (Capacity() <= 1) {
		  delete data_;
	  } else {
		  delete[] data_;
	  }
  }

  T& operator[](size_t index) {
	  return data_[index];
  }

  T* begin () { return data_; }
  T* end () { return end_; }
  const T* begin () const { return data_; }
  const T* end () const { return end_; }

  size_t Size() const {
	  return end_ - data_;
  }

  size_t Capacity() const {
	  return capacity_ - data_;
  }

  void PushBack(const T& value) {
	  if (new_) {
		  data_ = new T;
		  capacity_ = data_ + 1;
		  end_ = data_;
		  new_ = false;
	  }

	  if (Capacity() == Size()) {
		  T* new_data_ = new T[2 * Capacity()];
		  for (int i = 0; i < Size(); ++i) {
			  new_data_[i] = data_[i];
		  }
		  //delete[] data_;
		  //data_ = new_data_;
		  end_ = new_data_ + Size();
		  if (Capacity() <= 1) {
			  delete data_;
		  } else {
			  delete[] data_;
		  }
		  data_ = new_data_;
		  capacity_ = new_data_ + 2 * Size();

	  }
	  data_[Size()] = value;
	  end_ = end_ + 1;
  }

private:
  T* data_;
  T* end_;
  T* capacity_;
  bool new_ = true;
  // Добавьте поля для хранения данных вектора
};
