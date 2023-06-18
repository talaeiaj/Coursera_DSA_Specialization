#include <iostream>
#include <vector>
using std::vector;

int fibonacciLastDigit(long long n) {
    int current = 0, next = 1;

    for (long long i = 0; i < n; i++) {
        int temp = next;
        next = (current + next) % 10;
        current = temp;
    }

    return current;
}


long long get_fibonacci_partial_sum(long long from, long long to) {
    int sumTo = (fibonacciLastDigit((to + 2) % 60) + 9) % 10;
    int sumFrom = (fibonacciLastDigit((from + 1) % 60) + 9) % 10;
    return (sumTo - sumFrom + 10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
