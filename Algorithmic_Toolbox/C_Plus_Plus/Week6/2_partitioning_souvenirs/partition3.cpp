#include <iostream>
#include <vector>

using std::vector;

bool split(vector<int>& values){
    int v = 0, n = values.size();
    for (int value : values) {
        v += value;
    }

    if (v % 3 != 0) {
        return false;
    }
    v = v / 3;

    vector<vector<vector<bool> > > table(n + 1, vector<vector<bool> >(v + 1, vector<bool>(v + 1, false)));
    table[0][0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int s1 = 0; s1 <= v; s1++) {
            for (int s2 = 0; s2 <= v; s2++) {
                table[i][s1][s2] = table[i - 1][s1][s2];
                if (s1 >= values[i - 1]) {
                    table[i][s1][s2] = table[i][s1][s2] || table[i - 1][s1 - values[i - 1]][s2];
                }
                if (s2 >= values[i - 1]) {
                    table[i][s1][s2] = table[i][s1][s2] || table[i - 1][s1][s2 - values[i - 1]];
                }
            }
        }
    }

    return table[n][v][v];
}

int partition3(vector<int>& A){
    return (split(A) ? 1 : 0);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
