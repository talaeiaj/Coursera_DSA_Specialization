#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool compareNumbers(std::string num1, std::string num2) {
    return num1 + num2 > num2 + num1;
}

string largest_number(vector<string> a) {
  //write your code here

  std::sort(a.begin(), a.end(), compareNumbers);
  std::string result = "";
  for (const std::string& num : a) {
      result += num;
  }
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
