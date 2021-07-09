#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2, M = 22;

int n, m, w[M][M], w1[M], f[1 << M];
char s[N];

bool bit(int b, int i) {
    return b >> i & 1;
}

int main() {
    ios::sync_with_stdio(false);
    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        if (i == 1) continue;
        int u = s[i] - 'a', v = s[i - 1] - 'a';
        if (u == v) continue;
        ++w[u][v]; ++w[v][u];
        ++w1[u]; ++w1[v];
        ++sum;
    }
    for (int mk = 1; mk <= 1 << m; ++mk) {
        // if (__builtin_popcount(mk) < 2) continue;
        int tmp = 0;
        f[mk] = INT_MAX;
        for (int i = 0; i < m; ++i) if (bit(mk, i)) {
            f[mk] = min(f[mk], f[mk ^ (1 << i)]);
            for (int j = 0; j < m; ++j)
                if (!bit(mk, j)) tmp += w[i][j];
        }
        f[mk] += tmp;
    }
    cout << f[(1 << m) - 1] << "\n";
    return 0;
}
