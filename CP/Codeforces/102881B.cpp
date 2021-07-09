#include <bits/stdc++.h>

using namespace std;

int test;
long double edges[3], k;

int main() {
    freopen("sticks.in", "r", stdin);
    cin >> test;
    (cout << fixed).precision(9);
    while (test--) {
        cin >> edges[0] >> edges[1] >> edges[2] >> k;
        sort(edges, edges + 3);
        long double tmp = sqrt(edges[1] * edges[1] + edges[2] * edges[2]);
        long double tmp1 = min(tmp - edges[0], k * 1.0);
        edges[0] += tmp1;
        long double p = (edges[0] + edges[1] + edges[2]) / 2;
        long double a = sqrt(p * (p - edges[0]) * (p - edges[1]) * (p - edges[2]));
        cout << a << "\n";
    }
    return 0;
}