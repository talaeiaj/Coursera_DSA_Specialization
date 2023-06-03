#include <iostream>

int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return std::max(a, b);
    }
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
  int gcdValue = gcd(a, b);
  return static_cast<long long>(a) * b / gcdValue;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
