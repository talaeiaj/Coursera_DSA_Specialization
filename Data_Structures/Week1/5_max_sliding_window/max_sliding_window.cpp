#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::deque;

void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}
void maxSlidingWindow(vector<int> const & nums, int k) {
    deque<int> indices;
    int n = nums.size();

    // Process the first window
    for (int i = 0; i < k; ++i) {
        while (!indices.empty() && nums[i] >= nums[indices.back()])
            indices.pop_back();
        indices.push_back(i);
    }

    cout << nums[indices.front()] << " ";

    // Process the remaining windows
    for (int i = k; i < n; ++i) {
        // Remove elements that are outside the current window
        while (!indices.empty() && indices.front() <= i - k)
            indices.pop_front();

        // Remove elements that are smaller than the current element
        while (!indices.empty() && nums[i] >= nums[indices.back()])
            indices.pop_back();

        indices.push_back(i);
        cout << nums[indices.front()] << " ";
    }
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    maxSlidingWindow(A, w);

    return 0;
}
