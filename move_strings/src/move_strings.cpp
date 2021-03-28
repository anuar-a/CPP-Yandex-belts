#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings (vector<string>& source, vector<string>& destination) {
	for (auto word:source) {
		destination.push_back(word);
	}
	source.clear();
}

int main() {
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	cout << source.size() << " " << destination.size() << "\n";
	MoveStrings(source, destination);
	cout << source.size() << " " << destination.size();
	return 0;
}
