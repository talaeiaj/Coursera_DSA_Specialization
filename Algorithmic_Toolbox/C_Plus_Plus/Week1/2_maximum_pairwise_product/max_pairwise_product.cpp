#include <iostream>
#include <vector>
#include <algorithm>

long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    
    int n = numbers.size();

    int max_index1 = -1;
    int max_index2 = -1;

    for (int i = 0; i < n; i++) {
        if (max_index1 == -1 || numbers[i] > numbers[max_index1]) {
            max_index2 = max_index1;
            max_index1 = i;
        } else if (max_index2 == -1 || numbers[i] > numbers[max_index2]) {
            max_index2 = i;
        }
    }
    long long int max_product = static_cast<long long int>(numbers[max_index1]) * numbers[max_index2];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
