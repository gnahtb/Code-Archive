#include <bits/stdc++.h>

using namespace std;

int n, a, b, c[30], ans = INT_MAX;

int getbit(int m, int i) {
    return m >> i & 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int m = 0; m < 1 << n; ++m) {
        bool flag = true;
        for (int i = 0, j = n - 1; i < j; ++i, --j)
            if (getbit(m, i) != getbit(m, j)) flag = false;
        if (!flag) continue;
        for (int i = 0; i < n; ++i)
            if (c[i] < 2 && getbit(m, i) != c[i]) flag = false;
        if (!flag) continue;
        int cur = 0;
        for (int i = 0; i < n; ++i)
            if (c[i] == 2) cur += getbit(m, i) ? b : a;
        ans = min(ans, cur);
        // cout << m << " " << cur << "\n";
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    return 0;
}
