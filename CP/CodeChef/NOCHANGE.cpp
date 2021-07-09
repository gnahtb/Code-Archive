#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int test, n, p, d[N];

void Solve() {
    for (int i = 1; i <= n; ++i) {
        if (p % d[i] != 0) {
            cout << "YES ";
            for (int j = 1; j < i; ++j) cout << "0 ";
            int tmp = p / d[i] + 1;
            cout << tmp << " ";
            for (int j = i; j < n; ++j) cout << "0 ";
            cout << "\n";
            return;
        }
    }
    for (int i = 1; i < min(n, 30); ++i) {
        for (int j = i + 1; j <= n; ++j)
            if (d[j] % d[i] != 0) {
                cout << "YES ";
                int tmp1 = p / d[j] - 1;
                int tmp2 = d[j] / d[i] + 1;
                for (int it = 1; it < i; ++it) cout << "0 ";
                cout << tmp2 << " ";
                for (int it = i + 1; it < j; ++it) cout << "0 ";
                cout << tmp1 << " ";
                for (int it = j + 1; it <= n; ++it) cout << "0 ";
                cout << "\n";
                return;
            }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin >> test;
    while (test--) {
        cin >> n >> p;
        for (int i = 1; i <= n; ++i) cin >> d[i];
        Solve();
    }
    return 0;
}