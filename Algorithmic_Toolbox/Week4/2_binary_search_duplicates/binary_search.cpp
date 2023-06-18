#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int min_index = 0;
    int max_index = a.size() - 1;
    int result = -1;

    while (max_index >= min_index) {
        int mid_index = (min_index + max_index) / 2;

        if (a[mid_index] == x) {
            max_index = mid_index - 1;
            result = mid_index;
        } else if (a[mid_index] < x) {
            min_index = mid_index + 1;
        } else {
            max_index = mid_index - 1;
        }
    }
    return result;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
