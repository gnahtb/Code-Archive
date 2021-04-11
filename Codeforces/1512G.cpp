#include <bits/stdc++.h>

using namespace std;

const int LIM = 1e7;

int d[LIM + 2], ans[10000002];

int main() {
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= LIM; ++i) {
        for (int j = i; j <= LIM; j += i) d[j] = min(100000000, d[j] + i);
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= LIM; ++i)
        if (d[i] <= 10000000 && ans[d[i]] < 0) ans[d[i]] = i;
    int test;
    cin >> test;
    while (test--) {
        int c;
        cin >> c;
        cout << ans[c] << "\n";
    }
}