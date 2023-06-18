#include <iostream>

int pisanoPeriod(long long m) {
    int current = 0, next = 1;
    int period = 0;

    while (true) {
        int temp = next;
        next = (current + next) % m;
        current = temp;
        period++;

        if (current == 0 && next == 1)
            return period;
    }
}

int fibonacci_sum(long long n) {
    if (n <= 1)
        return n;

    int nNew = (n % pisanoPeriod(10)) + 2;
    int current = 0, next = 1;

    for (int i = 0; i < nNew; i++) {
        int temp = next;
        next = (current + next) % 10;
        current = temp;
    }

    return (current + 9) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
