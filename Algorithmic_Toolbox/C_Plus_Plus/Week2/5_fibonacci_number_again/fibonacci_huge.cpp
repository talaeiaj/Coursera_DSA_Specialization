#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> multiply_2x2_matrices(const vector<vector<long long>>& a, const vector<vector<long long>>& b, long long m) {
    vector<vector<long long>> c(2, vector<long long>(2));

    c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % m;
    c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % m;
    c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % m;
    c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % m;

    return c;
}

vector<vector<long long>> matrix_exponent(const vector<vector<long long>>& d, long long n, long long m) {
    if (n == 0) {
        return {{1, 0}, {0, 1}};
    } else if (n % 2 == 0) {
        vector<vector<long long>> z = matrix_exponent(d, n / 2, m);
        return multiply_2x2_matrices(z, z, m);
    } else {
        vector<vector<long long>> z = matrix_exponent(d, n / 2, m);
        vector<vector<long long>> y = multiply_2x2_matrices(z, z, m);
        return multiply_2x2_matrices(y, d, m);
    }
}


long long get_fibonacci_huge(long long n, long long m) {
    vector<vector<long long>> c = {{0,1},{1,1}};
    auto result = matrix_exponent(c, n, m);
    return result[0][1];
}
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
