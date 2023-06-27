#include <iostream>
#include <string>
#include <vector>

long long hash(const std::string &s, const long long &p, const long long &x) {
    long long hash{0};
    for (int i = s.size() - 1; i >= 0; --i) {
        hash = (hash * x + s[i]) % p;
    }
    return hash;
}

std::vector<long long> compute_hashes(const std::string &text, const size_t psize, const long long &p, const long long &x) {
    size_t size = text.size() - psize + 1;
    std::vector<long long> hashes(size);
    auto begin = text.begin() + size - 1;
    auto end = text.end();
    std::string last(begin, end);
    hashes[size - 1] = hash(last, p, x);
    long long x_to_psize = 1;
    for (int i = 1; i <= psize; ++i) {
        x_to_psize = (x_to_psize * x) % p;
    }
    for (int k = (int)size - 1; k > 0; --k) {
        hashes[k - 1] = (x * hashes[k] + text[k - 1] - text[k + psize - 1] * x_to_psize) % p;
        hashes[k - 1] = (hashes[k - 1] + p) % p;
    }
    return hashes;
}

std::vector<size_t> rabin_karp(const std::string &pattern, const std::string &text) {
    long long p{1299709};
    long long x{23};
    size_t psize = pattern.size();
    long long phash = hash(pattern, p, x);
    auto hashes = compute_hashes(text, psize, p, x);
    std::vector<size_t> indexes;
    for (size_t idx = 0; idx < hashes.size(); ++idx) {
        if (hashes[idx] == phash) {
            auto first = text.begin() + idx;
            auto last = text.begin() + idx + psize;
            std::string compare(first, last);
            if (compare == pattern) {
                indexes.push_back(idx);
            }
        }
    }
    return indexes;
}

template <class T> void display(const std::vector<T> &vector) {
    for (auto &v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string pattern, text;
    std::cin >> pattern;
    std::cin >> text;
    auto positions = rabin_karp(pattern, text);
    display(positions);
    return 0;
}
