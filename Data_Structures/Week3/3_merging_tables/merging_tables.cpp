#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSetsElement {
    int size, parent, rank;

    DisjointSetsElement(int sz = 0, int pt = -1, int rk = 0) : size(sz), parent(pt), rank(rk) {}
};

struct DisjointSets {
    int size;
    int max_table_size;
    vector<DisjointSetsElement> sets;

    DisjointSets(int sz) : size(sz), max_table_size(0), sets(size) {
        for (int i = 0; i < size; i++)
            sets[i].parent = i;
    }

    int getParent(int table) {
        int i = table;
        if (i != sets[i].parent)
            sets[i].parent = getParent(sets[i].parent);

        return sets[i].parent;
    }

    void merge(int destination, int source) {
        int realDestination = getParent(destination);
        int realSource = getParent(source);
        if (realDestination != realSource) {
            if (sets[realSource].rank > sets[realDestination].rank) {
                sets[realDestination].parent = realSource;
                sets[realSource].size += sets[realDestination].size;
                sets[realDestination].size = 0;
                max_table_size = max(max_table_size, sets[realSource].size);
            } else {
                sets[realSource].parent = realDestination;
                sets[realDestination].size += sets[realSource].size;
                sets[realSource].size = 0;
                max_table_size = max(max_table_size, sets[realDestination].size);

                if (sets[realSource].rank == sets[realDestination].rank)
                    sets[realDestination].rank += 1;
            }
        }
    }

    void input() {
        for (int i = 0; i < size; ++i) {
            cin >> sets[i].size;
            max_table_size = max(max_table_size, sets[i].size);
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DisjointSets tables(n);
    tables.input();

    int destination, source;
    for (int i = 0; i < m; i++) {
        cin >> destination >> source;
        --destination;
        --source;

        tables.merge(destination, source);
        cout << tables.max_table_size << endl;
    }

    return 0;
}
