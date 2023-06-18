#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int capacity, const vector<int> &weights) {
    int n = weights.size();
    std::vector<std::vector<bool>> pack(capacity + 1, std::vector<bool>(n + 1, false));
    pack[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] > w) {
                pack[w][i] = pack[w][i - 1];
            } else {
                pack[w][i] = pack[w][i - 1] || pack[w - weights[i - 1]][i - 1];
            }
        }
    }

    for (int s = capacity; s >= 0; s--) {
        if (pack[s][n]) {
            return s;
        }
    }
    
    return 0;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
