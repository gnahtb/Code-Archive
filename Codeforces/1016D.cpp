#include <bits/stdc++.h>

using namespace std;

int n, m, a[105], b[105], ans[105][105], e[205][10105], d[205];
bool canSolve[205];

int getbit(int m, int i) { return m >> i & 1; }

int getindex(int r, int c) { return m * (r - 1) + c; }

void build() {
    memset(e, 0, sizeof e);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 30; ++j)
            e[i][n * m + j] = getbit(a[i], j - 1);
        for (int j = 1; j <= m; ++j)
            e[i][getindex(i, j)] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= 30; ++j)
            e[i + n][n * m + j] = getbit(b[i], j - 1);
        for (int j = 1; j <= n; ++j)
            e[i + n][getindex(j, i)] = 1;
    }
}

void gauss()
{
    memset(canSolve, true, sizeof canSolve);
    for (int i = 1; i <= n + m; ++i) {
        int x = 0;
        for (int j = n * m; j > 0; --j) if (e[i][j]) x = j;
        if (!x) for (int j = 1; j <= 30; ++j)
            if (e[i][n * m + j]) canSolve[j] = false;
        for (int j = 1; j <= n + m; ++j) if (i != j && e[j][x])
            for (int k = 1; k <= n * m + 30; ++k) (e[j][k] += e[i][k]) &= 1;
    }   
}

void getsol(int u, vector<int> &vt) {
    for (int i = 1; i <= n * m; ++i)
        if (d[i] > 0 && e[d[i]][n * m + u]) vt.push_back(i);
}

void solve() {
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= 30; ++i)
        if (!canSolve[i]) { cout << "NO\n"; return; }
    cout << "YES\n";
    for (int i = 1; i <= n + m; ++i)
        for (int j = 1; j <= n * m; ++j)
            if (e[i][j]) d[j] = d[j] == 0 ? i : -1;
    for (int pw = 1; pw <= 30; ++pw) {
        vector<int> vt;
        getsol(pw, vt);
        for (int i : vt) {
            int r = (i - 1) / m + 1, c = i - m * (r - 1);
            ans[r][c] += 1 << (pw - 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << ans[i][j] << " ";
        cout << "\n";
    }
}

void print() {
    for (int i = 1; i <= n + m; ++i) {
        for (int j = 1; j <= n * m + 30; ++j) cout << e[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    build();
    gauss();
    // print();
    solve();
    return 0;
}
