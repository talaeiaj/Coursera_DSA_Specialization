#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int get_change(int money) {
  vector<int> table(money + 1, INT_MAX);
  table[0] = 0;

  for (int m = 1; m <= money; m++) {
    for (int coin : {1, 3, 4}) {
      if (coin <= m) {
        table[m] = min(table[m], table[m - coin] + 1);
      }
    }
  }

  return table[money];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
