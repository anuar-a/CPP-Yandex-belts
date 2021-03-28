#include "http_request.h"
#include "stats.h"
#include <string_view>
#include <map>
using namespace std;

void Stats::AddMethod(string_view method) {
  auto it = methods.find(method);
  if (it != methods.end()) {
	  methods[it->first]++;
  } else {
	  methods["UNKNOWN"]++;
  }
}

void Stats::AddUri(string_view uri) {
  auto it = uris.find(uri);
  if (it != uris.end()) {
	  uris[it->first]++;
  } else {
	  uris["unknown"]++;
  }
}

const map<string_view, int>& Stats::GetMethodStats() const {
  return methods;
}

const map<string_view, int>& Stats::GetUriStats() const {
  return uris;
}

HttpRequest ParseRequest(string_view line) {
	HttpRequest request;
	auto it = line.find_first_not_of(' ');
	line.remove_prefix(it);
	size_t space = line.find(' ');
	request.method = line.substr(0, space);
	line.remove_prefix(space + 1);
	space = line.find(' ');
	request.uri = line.substr(0, space);
	line.remove_prefix(space + 1);
	space = line.find(' ');
	request.protocol = line.substr(0, space);
	return request;
}
