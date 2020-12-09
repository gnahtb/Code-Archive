#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 2, lN = 20;
const int K = 1e6 + 2;

int n, a[N], g[lN][N];
ll cnt[K];

int get_gcd(int l, int r) {
    int d = r - l + 1, ld = __lg(d);
    return __gcd(g[ld][l], g[ld][r - (1 << ld) + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        g[0][i] = a[i];
    }
    for (int j = 1; 1 << j <= n; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            g[j][i] = __gcd(g[j - 1][i], g[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cur = a[i], j = i;
        while (j <= n) {
            int l = j + 1, r = n, x = n + 1;
            while (l <= r) {
                int m = (l + r) >> 1;
                if (get_gcd(i, m) < cur) {
                    x = m;
                    r = m - 1;
                } else l = m + 1;
            }
            if (cur <= 1e6) cnt[cur] += x - j;
            j = x;
            cur = get_gcd(i, j);
        }
    }
    for (int i = 1e6; i; --i) {
        for (int j = i * 2; j <= 1e6; j += i) {
            cnt[j] += cnt[i];
        }
    }
    int q;
    for (cin >> q; q; --q) {
        int k;
        cin >> k;
        cout << cnt[k] << "\n";
    }
    return 0;
}