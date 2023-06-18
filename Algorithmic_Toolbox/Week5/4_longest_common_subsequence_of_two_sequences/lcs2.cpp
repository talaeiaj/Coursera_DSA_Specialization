#include <iostream>
#include <vector>

using namespace std;

int lcs2(const vector < int > & first, const vector < int > & second) {
  int m = first.size();
  int n = second.size();

  vector < std::vector < int >> table(m + 1, vector < int > (n + 1, 0));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      table[i][j] = max(table[i - 1][j], table[i][j - 1]);
      if (first[i - 1] == second[j - 1]) {
        table[i][j] = max(table[i][j], table[i - 1][j - 1] + 1);
      }
    }
  }

  return table[m][n];
}

int main() {
  size_t n;
  std::cin >> n;
  vector < int > a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector < int > b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}