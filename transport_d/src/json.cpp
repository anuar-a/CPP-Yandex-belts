#include "json.h"
#include <iostream>
using namespace std;

namespace Json {

  Document::Document(Node root) : root(move(root)) {
  }

  const Node& Document::GetRoot() const {
    return root;
  }

  Node LoadNode(istream& input);

  Node LoadArray(istream& input) {
    vector<Node> result;

    for (char c; input >> c && c != ']'; ) {
      if (c != ',') {
        input.putback(c);
      }
      result.push_back(LoadNode(input));
    }

    return Node(move(result));
  }

  Node LoadInt(istream& input) {
	int result = 0;
    double result_double = 0;

    if (input.peek() == '-') {
    	input >> result_double;
    	return Node(result_double);
    }
    while (isdigit(input.peek())) {
      result *= 10;
      result += input.get() - '0';
    }
    if (input.peek() == '.') {
    	input.ignore(1);
    	result_double = result;
    	for (int i = 1; isdigit(input.peek()); ++i) {
    		result_double += ((input.get() - '0')/(pow(10, i)));
    	}
    	return Node(result_double);
    }
    return Node(result);
  }

  Node LoadString(istream& input) {
    string line;
    getline(input, line, '"');
    return Node(move(line));
  }

  Node LoadDict(istream& input) {
    map<string, Node> result;

    for (char c; input >> c && c != '}'; ) {
      if (c == ',') {
        input >> c;
      }

      string key = LoadString(input).AsString();
      input >> c;
      result.emplace(move(key), LoadNode(input));
    }

    return Node(move(result));
  }

  Node LoadBool(istream& input) {
      bool line;
      string s;
      //input >> s;
      if (input.peek() == 't') {
    	  input.ignore(4);
    	  line = true;
      } else if (input.peek() == 'f') {
    	  input.ignore(5);
    	  line = false;
      }
      return Node(line);
  }

  Node LoadNode(istream& input) {
    char c;
    input >> c;

    if (c == '[') {
      return LoadArray(input);
    } else if (c == '{') {
      return LoadDict(input);
    } else if (c == '"') {
      return LoadString(input);
    } else if (c == 't' || c == 'f') {
    	input.putback(c);
    	return LoadBool(input);
    }
      else {
      input.putback(c);
      return LoadInt(input);
    }
  }

  Document Load(istream& input) {
    return Document{LoadNode(input)};
  }

}
