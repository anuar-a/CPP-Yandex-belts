#include "test_runner.h"
#include "profile.h"

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <future>
#include <functional>
using namespace std;

template <typename Iterator>
class IteratorRange {
public:
  IteratorRange(Iterator begin, Iterator end)
    : first(begin)
    , last(end)
    , size_(distance(first, last))
  {
  }

  Iterator begin() const {
    return first;
  }

  Iterator end() const {
    return last;
  }

  size_t size() const {
    return size_;
  }

private:
  Iterator first, last;
  size_t size_;
};

template <typename Iterator>
class Paginator {
private:
  vector<IteratorRange<Iterator>> pages;

public:
  Paginator(Iterator begin, Iterator end, size_t page_size) {
    for (size_t left = distance(begin, end); left > 0; ) {
      size_t current_page_size = min(page_size, left);
      Iterator current_page_end = next(begin, current_page_size);
      pages.push_back({begin, current_page_end});

      left -= current_page_size;
      begin = current_page_end;
    }
  }

  auto begin() const {
    return pages.begin();
  }

  auto end() const {
    return pages.end();
  }

  size_t size() const {
    return pages.size();
  }
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
  return Paginator(begin(c), end(c), page_size);
}

struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other) {
	  for (auto& item : other.word_frequences) {
		  word_frequences[item.first] += item.second;
	  }
  }
};

Stats ExploreLine(const set<string>& key_words, const string& line) {
	Stats result;
	stringstream ss(line);
	string word;
	while (ss >> word) {
		if (key_words.count(word) > 0) {
			result.word_frequences[word]++;
		}
	}
	return result;
}
template<typename StringVector>
Stats ExploreKeyWordsSingleThread(
  StringVector& lines, const set<string>& key_words
) {
  Stats result;
  for (string& line : lines) {
    result += ExploreLine(key_words, line);
  }

  return result;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
  // Реализуйте эту функцию
	Stats result;
	vector<string> lines;
	vector<future<Stats>> futures;
	string line;
	while(getline(input, line)) {
		lines.push_back(line);
	}
	const auto size = lines.size();

	size_t page_size = size/4;
	if (page_size * 4 < size) {
		page_size++;
	}
	for (auto page : Paginate(lines, page_size)) {
		futures.push_back(async([page, &key_words]{return ExploreKeyWordsSingleThread(page, key_words);}));
	}
	//future<Stats> f =   async([&]{return ExploreKeyWordsSingleThread(line, key_words);});

	for (auto& f : futures) {
		result += f.get();
	}
	//result += f.get();
	return result;

}

void TestBasic() {
  const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
  ss << "this new yangle service really rocks\n";
  ss << "It sucks when yangle isn't available\n";
  ss << "10 reasons why yangle is the best IT company\n";
  ss << "yangle rocks others suck\n";
  ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
}
