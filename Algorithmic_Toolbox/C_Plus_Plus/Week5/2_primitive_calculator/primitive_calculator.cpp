#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector < int > optimal_sequence(int n) {
  vector < int > table(n + 1, INT8_MAX);
  table[1] = 0;

  for (int k = 2; k <= n; k++) {
    table[k] = 1 + table[k - 1];
    if (k % 2 == 0) {
      table[k] = std::min(table[k], 1 + table[k / 2]);
    }
    if (k % 3 == 0) {
      table[k] = std::min(table[k], 1 + table[k / 3]);
    }
  }

  std::vector < int > operations;
  while (n > 1) {
    operations.push_back(n);
    if (table[n] == 1 + table[n - 1]) {
      n = n - 1;
    } else if (n % 2 == 0 && table[n] == 1 + table[n / 2]) {
      n = n / 2;
    } else if (n % 3 == 0 && table[n] == 1 + table[n / 3]) {
      n = n / 3;
    }
  }

  operations.push_back(1);
  std::reverse(operations.begin(), operations.end());

  return operations;
}

int main() {
  int n;
  std::cin >> n;
  vector < int > sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}