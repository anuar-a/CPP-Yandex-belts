#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;


bool IsSubdomain(const string& subdomain, const string& domain) {
    int i = 0;
    int j = 0;
    while (i < subdomain.size() && j < domain.size()) {
        if (subdomain[i++] != domain[j++]) {
            return false;
        }
    }
    if (subdomain.size() != domain.size()) {
        return (j == domain.size() && subdomain[i] == '.') ||
               (i == subdomain.size() && domain[j] == '.');
    }
    return true;
}

vector<string> ReadDomains(istream& is) {
  size_t count;
  is >> count;

  vector<string> domains;
  for (size_t i = 0; i < count; ++i) {
    string domain;
    is >> domain;
    reverse(begin(domain), end(domain));
    domains.push_back(domain);
  }
  return domains;
}

void ProcessBannedDomains(vector<string>& banned_domains) {

	  sort(begin(banned_domains), end(banned_domains));

	  size_t insert_pos = 0;
	  for (string& domain : banned_domains) {
	    if (insert_pos == 0 || !IsSubdomain(domain, banned_domains[insert_pos - 1])) {
	      swap(banned_domains[insert_pos++], domain);
	    }
	  }
	  banned_domains.resize(insert_pos);
}

string CheckBanned (const string& domain, vector<string>& banned_domains) {
	if (const auto it = upper_bound(begin(banned_domains), end(banned_domains), domain);
		it != begin(banned_domains) && IsSubdomain(domain, *prev(it))) {
	  return "Bad";
	} else {
	  return "Good";
	}
}

int main() {

  vector<string> banned_domains = ReadDomains(cin);
  vector<string> domains_to_check = ReadDomains(cin);
  ProcessBannedDomains(banned_domains);
  for (const auto& domain : domains_to_check) {
	  cout << CheckBanned(domain, banned_domains) << endl;
  }
  return 0;
}
