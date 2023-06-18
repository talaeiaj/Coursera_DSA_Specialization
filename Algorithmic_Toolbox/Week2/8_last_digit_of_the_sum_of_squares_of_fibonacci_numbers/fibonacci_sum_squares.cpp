#include <iostream>

int fibonacci_sum_squares(long long n) {
    // using the Pisano period (60) for m = 10 
    n = n % 60;

    int prev = 0, cur = 1;
    for (int i = 0; i < n; i++) {
        int temp = cur;
        cur = (prev + cur) % 10;
        prev = temp;
    }

    return (prev * cur) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
