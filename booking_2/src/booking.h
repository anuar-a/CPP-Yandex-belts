#pragma once

#include <iostream>

using namespace std;

namespace RAII {

template <typename Provider>
class Booking {
public:
	Booking() = default;
	Booking(Provider* provider, int counter):provider_(provider), counter_(counter){
	}
	Booking(const Booking&) = delete;
	Booking(Booking&& other) {
		provider_ = move(other.provider_);
		other.provider_ = nullptr;
	}

	Booking& operator=(const Booking&) = delete;
	Booking& operator=(Booking&& other) {
		provider_ = move(other.provider_);
		other.provider_ = nullptr;
		return *this;
	}

	~Booking() {
		if (provider_) provider_->CancelOrComplete(*this);
	}
private:
	Provider* provider_;
	int counter_;
};

}
