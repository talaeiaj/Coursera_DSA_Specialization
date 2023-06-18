#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;
using std::stack;


class StackWithMax {
   stack<std::pair<int, int>> elements;

public:
    void push(int val) {
        int cur_max = elements.empty() ? val : std::max(val, elements.top().second);
        elements.push(std::make_pair(val, cur_max));
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop();
        }
    }

    int top() {
        return elements.empty() ? -1 : elements.top().first;
    }

    int max() {
        return elements.empty() ? -1 : elements.top().second;
    }

    bool empty() {
        return elements.empty();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.pop();
        }
        else if (query == "max") {
            cout << stack.max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}