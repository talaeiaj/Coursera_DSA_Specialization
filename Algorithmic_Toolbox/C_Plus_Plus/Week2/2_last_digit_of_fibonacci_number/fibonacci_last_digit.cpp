#include <iostream>

int get_fibonacci_last_digit(int n) {
    if (n <= 1)
        return n;
    
    int prev = 0;
    int curr = 1;

    for (int i = 2; i <= n; i++) {
        int temp = (prev + curr) % 10;
        prev = curr;
        curr = temp;
    }

    return curr;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    }
