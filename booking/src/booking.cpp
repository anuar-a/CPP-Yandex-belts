#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <cstdint>
#include <map>
using namespace std;

struct Booking {
	int64_t time_;
	string hotel_name_;
	int client_id_;
	int room_count_;
};

class BookingManager {
public:
	void Add(Booking& booking) {
		bookings.push_back(booking);
		rooms[booking.hotel_name_] += booking.room_count_;
		clients[booking.hotel_name_][booking.client_id_] += 1;
	}
	int Clients(string& hotel_name) {
		Update();
		return clients[hotel_name].size();
	}
	int Rooms(string& hotel_name) {
		Update();
		return rooms[hotel_name];
	}
	void Update() {
		if (!bookings.empty()) {
			const int64_t time = bookings.back().time_;
			while(!bookings.empty() && bookings.front().time_ <= time - 86400) {
				rooms[bookings.front().hotel_name_] -= bookings.front().room_count_;
				clients[bookings.front().hotel_name_][bookings.front().client_id_] -= 1;
				if (clients[bookings.front().hotel_name_][bookings.front().client_id_] == 0) {
					clients[bookings.front().hotel_name_].erase(bookings.front().client_id_);
				}
				bookings.pop_front();
			}
		}
	}
private:
	deque<Booking> bookings;
	map<string, int> rooms;
	map<string, map<int, int>> clients;
};
//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	BookingManager bm;
	int q;
	cin >> q;
	string command;
	for (int i = 0; i < q; ++i) {
		cin >> command;
		if (command == "BOOK") {
			Booking b;
			cin >> b.time_;
			cin >> b.hotel_name_;
			cin >> b.client_id_;
			cin >> b.room_count_;
			bm.Add(b);
		} else if (command == "CLIENTS") {
			string hotel_name;
			cin >> hotel_name;
			cout << bm.Clients(hotel_name) << endl;
		} else if (command == "ROOMS") {
			string hotel_name;
			cin >> hotel_name;
			cout << bm.Rooms(hotel_name) << endl;
		}
	}
	return 0;
}
