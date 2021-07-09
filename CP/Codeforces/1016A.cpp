#include <iostream>

using namespace std;

const int N = 2E5 + 5;

int n, m, a[N];

void solve() {
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        int t = 0;
        if (m - cur <= a[i]) {
            a[i] -= m - cur;
            cur = a[i] % m;
            t += a[i] / m + 1;
        } else cur += a[i];
        cout << t << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    solve();
    return 0;
}
