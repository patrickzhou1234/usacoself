// http://www.usaco.org/index.php?page=viewproblem2&cpid=377
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    freopen("slowdown.in", "r", stdin);
    freopen("slowdown.out", "w", stdout);
    int n, inp;
    char chin;
    cin >> n;
    vector<int> t, d;
    for (int i = 0; i < n; i++) {
        cin >> chin >> inp;
        if (chin == 'T') {
            t.push_back(inp);
        } else {
            d.push_back(inp);
        }
    }
    sort(t.begin(), t.end());
    sort(d.begin(), d.end());
    int deeps = 1;
    double time = 0, dist = 0;
    while (!t.empty() && !d.empty()) {
        int t_tmp = t.front();
        double dt_tmp = dist + (t_tmp - time) * 1.0 / deeps; // look here!
        int d_tmp = d.front();
        if (dt_tmp < d_tmp) {
            dist += (t_tmp - time) * 1.0 / deeps; // look here!
            time = t_tmp;
            t.erase(t.begin());
        }
        if (dt_tmp > d_tmp) {
            time += (d_tmp - dist) * deeps;
            dist = d_tmp;
            d.erase(d.begin());
        }
        if (dt_tmp == d_tmp) {
            time = t_tmp; // look here!
            dist = d_tmp; // look here!
            d.erase(d.begin());
            t.erase(t.begin());
            deeps++;
        }
        deeps++;
    }
    while (!t.empty()) {
        int t_tmp = t.front();
        dist += (t_tmp - time) * 1.0 / deeps;  // look here!
        time = t_tmp;
        t.erase(t.begin());
        deeps++;  // look here!
    }
    while (!d.empty()) {
        int d_tmp = d.front();
        time += (d_tmp - dist) * deeps;
        dist = d_tmp;    // look here!
        d.erase(d.begin());
        deeps++;   // look here!
    }

    if (dist < 1000) {
        time += (1000 - dist) * deeps;
    }

    cout << fixed << (int) (round(time)) << endl;

    return 0;
}