#include <iostream>

#include <vector>

#include <string>

#include <map>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::map;

struct Query {
  string type, name;
  int number;
};

vector < Query > read_queries() {
  int n;
  cin >> n;
  vector < Query > queries(n);
  for (int i = 0; i < n; ++i) {
    cin >> queries[i].type;
    if (queries[i].type == "add")
      cin >> queries[i].number >> queries[i].name;
    else
      cin >> queries[i].number;
  }
  return queries;
}

void write_responses(const vector < string > & result) {
  for (const auto & response: result)
    cout << response << "\n";
}

vector < string > process_queries(const vector < Query > & queries) {
  vector < string > result;
  map < int, string > contacts;
  for (const auto & query: queries) {
    if (query.type == "add") {
      contacts[query.number] = query.name;
    } else if (query.type == "del") {
      contacts.erase(query.number);
    } else {
      string response = "not found";
      auto it = contacts.find(query.number);
      if (it != contacts.end()) {
        response = it -> second;
      }
      result.push_back(response);
    }
  }
  return result;
}

int main() {
  write_responses(process_queries(read_queries()));
  return 0;
}