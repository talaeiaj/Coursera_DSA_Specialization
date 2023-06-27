#include <algorithm>

#include <cmath>

#include <iostream>

#include <vector>

using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;
using std::vector;

class HeapBuilder {
  private: vector < int > data_;
  vector < pair < int,
  int >> swaps;

  void WriteResponse() const {
    cout << swaps.size() << "\n";
    for (const auto & swap: swaps) {
      cout << swap.first << " " << swap.second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int leftValue(int i) {
    return 2 * i + 1;
  }

  int rightValue(int i) {
    return 2 * i + 2;
  }

  void swimDown(int i) {
    int minIndex = i;
    int l = leftValue(i);
    if (l < data_.size() && data_[l] < data_[minIndex])
      minIndex = l;
    int r = rightValue(i);
    if (r < data_.size() && data_[r] < data_[minIndex])
      minIndex = r;
    if (i != minIndex) {
      swap(data_[i], data_[minIndex]);
      swaps.push_back(make_pair(i, minIndex));
      swimDown(minIndex);
    }
  }

  void GenerateSwaps() {
    swaps.clear();

    int n = data_.size();
    for (int i = (n - 1) / 2; i >= 0; i--) {
      swimDown(i);
    }
  }

  public: void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}