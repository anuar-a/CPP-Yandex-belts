#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Deque {
private:
	vector<T> front, back;
public:
	Deque() {

	}

	bool Empty() const {
		return front.empty() && back.empty();
	}

	const size_t Size() const {
		return front.size() + back.size();
	}

	T& operator[](size_t index) {
		if (index >= front.size()) {
			return back[index - front.size()];
		} else {
			return front[front.size() - 1 - index];
		}
	}

	const T& operator[](size_t index) const {
		if (index >= front.size()) {
			return back[index - front.size()];
		} else {
			return front[front.size() - 1 - index];
		}
	}

	void PushFront (const T& item) {
		front.push_back(item);
	}

	void PushBack (const T& item) {
		back.push_back(item);
	}

	T& Front() {
		if (front.empty()) {
			return back.front();
		}
		return front.back();
	}

	T& Back() {
		if (back.empty()) {
			return front.front();
		}
		return back.back();
	}

	const T& Front() const {
		if (front.empty()) {
			return back.front();
		}
		return front.back();
	}

	const T& Back() const {
		if (back.empty()) {
			return front.front();
		}
		return back.back();
	}

	T& At(size_t index) {
		if (index >= Size()) {
			throw out_of_range("Out of range");
		} else {
			if (index >= front.size()) {
							return back[index - front.size()];
						} else {
							return front[front.size() - 1 - index];
						}
					}
	}

	const T& At(size_t index) const {
		if (index >= Size()) {
			throw out_of_range("Out of range");
		} else {
			if (index >= front.size()) {
							return back[index - front.size()];
						} else {
							return front[front.size() - 1 - index];
						}
					}
	}
};

int main() {
	return 0;
}
