#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

pair<int, int> partition3(vector<int>& a, int l, int r) {
  int x = a[l];
  int low = l;
  int high = r;
  int i = l;

  while (i <= high) {
    if (a[i] < x) {
      swap(a[i], a[low]);
      i++;
      low++;
    } else if (a[i] > x) {
      swap(a[i], a[high]);
      high--;
    } else {
      i++;
    }
  }
  return {low, high};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  pair<int, int> bounds = partition3(a, l, r);
  randomized_quick_sort(a, l, bounds.first - 1);
  randomized_quick_sort(a, bounds.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
