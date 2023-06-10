#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long evaluate(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string& exp)
{
    int n = exp.size();

    const long long INF = numeric_limits<long long>::max();
    const long long NINF = numeric_limits<long long>::min();

    vector<vector<long long> > mins(n + 1, vector<long long>(n + 1, INF));
    vector<vector<long long> > maxs(n + 1, vector<long long>(n + 1, NINF));

    for (int i = 0; i <= n; i += 2) {
        mins[i][i + 1] = exp[i] - '0';
        maxs[i][i + 1] = exp[i] - '0';
    }

    for (int size = 3; size <= n; size += 2) {
        for (int l = 0; l + size <= n; l += 2) {
            int r = l + size;
            for (int m = l + 1; m < r; m += 2) {
                char oper = exp[m];
                vector<long long> cases = {
                    evaluate(mins[l][m], mins[m + 1][r], oper),
                    evaluate(mins[l][m], maxs[m + 1][r], oper),
                    evaluate(maxs[l][m], mins[m + 1][r], oper),
                    evaluate(maxs[l][m], maxs[m + 1][r], oper)
                };
                mins[l][r] = min(mins[l][r], *min_element(cases.begin(), cases.end()));
                maxs[l][r] = max(maxs[l][r], *max_element(cases.begin(), cases.end()));
            }
        }
    }

    return maxs[0][n];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
