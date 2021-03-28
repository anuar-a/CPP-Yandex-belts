#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class ReadingManager {
public:
  ReadingManager():users_bool(MAX_USER_COUNT_, false), users(MAX_USER_COUNT_, 0), pages(1000, 0){}

  void Read(int user_id, int page_count) {
	if (users_bool[user_id]) {
		pages[users[user_id]] -= 1;
	}
	users_count.insert(user_id);
	pages[page_count] += 1;
    users[user_id] = page_count;
    users_bool[user_id] = true;
  }

  double Cheer(int user_id) const {
    if (users_bool[user_id] != true) {
      return 0;
    }
    const int user_count = GetUserCount();
    if (user_count == 1) {
      return 1;
    }
    const int page_count = users[user_id];
    //int position = count_if(users.begin(), users.end(), [page_count, user_id](const pair<int, int> p){return p.second < page_count && p.first != user_id;});
    int position = 0;
    for (int i = 0; i < 1001; ++i) {
    	if (i < page_count) {
    		position += pages[i];
    	}
    }
    // ѕо умолчанию деление целочисленное, поэтому
    // нужно привести числитель к типу double.
    // ѕростой способ сделать это Ч умножить его на 1.0.
    return position * 1.0 / (user_count - 1);
  }
//
private:
  // —татическое поле не принадлежит какому-то конкретному
  // объекту класса. ѕо сути это глобальна€ переменна€,
  // в данном случае константна€.
  // Ѕудь она публичной, к ней можно было бы обратитьс€ снаружи
  // следующим образом: ReadingManager::MAX_USER_COUNT.
  static const int MAX_USER_COUNT_ = 100'000;

  set<int> users_count;
  vector<int> users;
  vector<bool> users_bool;
  vector<int> pages;
  vector<int> user_page_counts_;
  vector<int> sorted_users_;   // отсортированы по убыванию количества страниц
  vector<int> user_positions_; // позиции в векторе sorted_users_

  int GetUserCount() const {
    return users_count.size();
  }

int main() {
  // ƒл€ ускорени€ чтени€ данных отключаетс€ синхронизаци€
  // cin и cout с stdio,
  // а также выполн€етс€ отв€зка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
