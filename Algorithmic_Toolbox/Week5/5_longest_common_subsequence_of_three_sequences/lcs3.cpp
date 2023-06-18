#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs3(vector < int > & first, vector < int > & second, vector < int > & third) {
  int m = first.size();
  int n = second.size();
  int p = third.size();

  vector < vector < vector < int >>> table(m + 1, vector < vector < int >> (n + 1, vector < int > (p + 1, 0)));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= p; k++) {
        table[i][j][k] = max(table[i - 1][j][k], max(table[i][j - 1][k], table[i][j][k - 1]));
        if (first[i - 1] == second[j - 1] && second[j - 1] == third[k - 1]) {
          table[i][j][k] = max(table[i][j][k], table[i - 1][j - 1][k - 1] + 1);
        }
      }
    }
  }

  return table[m][n][p];
}

int main() {
  size_t an;
  std::cin >> an;
  vector < int > a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector < int > b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector < int > c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}