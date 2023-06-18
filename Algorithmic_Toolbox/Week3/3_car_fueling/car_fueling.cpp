#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);
    int num_refills = 0;
    int cur_refill = 0;
    while (cur_refill <= stops.size() - 2) {
        int last_refill = cur_refill;
        while (cur_refill <= stops.size() - 2 && stops[cur_refill + 1] - stops[last_refill] <= tank) {
            cur_refill += 1;
        }
        if (cur_refill == last_refill) {
            return -1;
        }
        if (cur_refill <= stops.size() - 2) {
            num_refills += 1;
        }
    }
    return num_refills;

}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
