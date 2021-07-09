#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int LIM = 2005;
struct HashTable2D {
    const static ll BASE1 = 31, BASE2 = 43;
    const static ll MOD = 1000000007;

    ll pw1[LIM], pw2[LIM];

    int row, col;
    ll a[LIM][LIM];

    void init(int _row, int _col) {
        row = _row;
        col = _col;
        pw1[0] = pw2[0] = 1;
        for (int i = 1; i <= row; ++i) pw1[i] = pw1[i - 1] * BASE1 % MOD;
        for (int i = 1; i <= col; ++i) pw2[i] = pw2[i - 1] * BASE2 % MOD;
    }

    void build(int (&_a)[LIM][LIM]) {
        fill(a[0], a[LIM], 0);
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j)
                a[i][j] = (a[i][j - 1] * BASE2 + _a[i][j]) % MOD;
            for (int j = 1; j <= col; ++j)
                a[i][j] = (a[i - 1][j] * BASE1 + a[i][j]) % MOD;
        }
    }

    ll get_hash(int i, int j, int x, int y) {
        int i1 = i + x - 1, j1 = j + y - 1;
        ll tmp1 = (a[i1][j1] + (MOD - a[i - 1][j1]) * pw1[x] % MOD) % MOD;
        ll tmp2 = (a[i1][j - 1] + (MOD - a[i - 1][j - 1]) * pw1[x] % MOD) % MOD;
        ll ret = (tmp1 + (MOD - tmp2) * pw2[y] % MOD) % MOD;
        return ret;
    }
} ht1, ht2;

int n, m;
int a1[LIM][LIM], a2[LIM][LIM];

void read_tab(int row, int col, int (&_a)[LIM][LIM]) {
    for (int i = 1; i <= row; ++i)
        for (int j = 1; j <= col; ++j) {
            char ch;
            cin >> ch;
            _a[i][j] = ch - 'a' + 1;
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    read_tab(n, m, a1);
    ht1.init(n, m);
    ht1.build(a1);
    read_tab(m, n, a2);
    ht2.init(m, n);
    ht2.build(a2);
    for (int i = 1; i + m - 1 <= n; ++i)
        for (int j = 1; j + m - 1 <= n; ++j)
            if (ht1.get_hash(i, 1, m, m) == ht2.get_hash(1, j, m, m)) {
                cout << i << " " << j << "\n";
                return 0;
            }
    return 0;
}
