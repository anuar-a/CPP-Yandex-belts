#include <string>
#include <vector>
using namespace std;

#define LIT(a, b) a ## b
#define MACRO(a, b) LIT(a, b)
#define UNIQ_ID MACRO(id_, __LINE__)

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}
