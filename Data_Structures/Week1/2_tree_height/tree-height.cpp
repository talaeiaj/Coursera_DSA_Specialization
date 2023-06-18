#include <iostream>
#include <vector>

int dfs(int r, const std::vector<std::vector<int>>& adj) {
    if (adj[r].empty())
        return 1;
    else {
        int maxv = 0;
        for (int j : adj[r])
            maxv = std::max(maxv, dfs(j, adj));
        return 1 + maxv;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> p(n);
    int r = -1;

    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        if (p[i] == -1)
            r = i;
    }

    std::vector<std::vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        if (p[i] != -1)
            adj[p[i]].push_back(i);
    }

    std::cout << dfs(r, adj) << std::endl;
}
