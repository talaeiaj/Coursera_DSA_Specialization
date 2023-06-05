#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  //we need to find the largest value of k such that k(k+1)/2 <= n
  int k = 1;
  while (k * (k + 1) / 2 <= n) {
      k++;
  }
  k--;

  int delta = n - k * (k + 1) / 2;
  std::vector<int> prizes;
  for (int i = 0; i < k-1; i++) {
      prizes.push_back(i+1);
  }
  prizes.push_back(k + delta);
  return prizes;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
