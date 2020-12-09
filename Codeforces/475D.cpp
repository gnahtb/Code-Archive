#include <bits/stdc++.h>

using namespace std;

#define long long long

const int N_MAX = 1E5 + 5, LG_MAX = 20;

int n, q, a[N_MAX], t[LG_MAX][N_MAX];
map<int, long> cnt;

void build() {
    memset(t, -1, sizeof t);
    for (int i = 1; i <= n; ++i)
        t[0][i] = a[i];
    for (int j = 1; 1 << j <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            t[j][i] = __gcd(t[j - 1][i], t[j - 1][i + (1 << (j - 1))]);
}

int get(int l, int r) {
    int tmp = __lg(r - l + 1);
    return __gcd(t[tmp][l], t[tmp][r - (1 << tmp) + 1]);
}

void prep() {
    for (int i = 1; i <= n; ++i)
        for (int j = i, cur = a[i], x; j <= n; j = x + 1, cur = get(i, j)) {
            int l = j, r = n; x = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (get(i, m) == cur) x = m, l = m + 1;
                else r = m - 1;
            }
            cnt[cur] += x - j + 1;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build();
    prep();
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (cnt.find(x) == cnt.end()) cout << "0\n";
        else cout << cnt[x] << "\n";
    }
    return 0;
}
