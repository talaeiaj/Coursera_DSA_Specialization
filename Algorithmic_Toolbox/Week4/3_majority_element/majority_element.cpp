#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) {
        return -1;
    }
    if (left + 1 == right) {
        return a[left];
    }
    int middle = (left + right) / 2;
    int x = get_majority_element(a, left, middle);
    int count = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    if (2 * count > right - left) {
        return x;
    }
    x = get_majority_element(a, middle, right);
    count = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    if (2 * count > right - left) {
        return x;
    }
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
