#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here

      while (capacity > 0) {
        int m = -1;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > 0) {
                if (m == -1 || values[i] * weights[m] > values[m] * weights[i]) {
                    m = i;
                }
            }
        }
        if (m == -1) {
            break;
        }
        int amount = std::min(weights[m], capacity);
        value += static_cast<double>(values[m]) * amount / weights[m];
        capacity -= amount;
        weights[m] -= amount;
    }
    
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
