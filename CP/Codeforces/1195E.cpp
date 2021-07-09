#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LIM = 3002;

int n, m, a, b;
ll g0, x, y, z, ar[LIM][LIM], mn[LIM][LIM], ans;
deque<int> dq;

void prep() {
    for (int i = 1; i <= n; ++i) {
        dq.clear();
        for (int j = 1; j <= m; ++j) {
            while (!dq.empty() && dq.front() <= j - b) dq.pop_front();
            while (!dq.empty() && ar[i][dq.back()] >= ar[i][j]) dq.pop_back();
            dq.push_back(j);
            if (j >= b) mn[i][j] = ar[i][dq.front()];
        }
    }
}

void solve() {
    for (int j = b; j <= m; ++j) {
        dq.clear();
        for (int i = 1; i <= n; ++i) {
            while (!dq.empty() && dq.front() <= i - a) dq.pop_front();
            while (!dq.empty() && mn[dq.back()][j] >= mn[i][j]) dq.pop_back();
            dq.push_back(i);
            if (i >= a) ans += mn[dq.front()][j];
        }
    }
}

int main() {
    cin >> n >> m >> a >> b >> g0 >> x >> y >> z;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            ar[i][j] = g0;
            ((g0 *= x) += y) %= z;
        }
    prep();
    solve();
    cout << ans << "\n";
    return 0;
}
