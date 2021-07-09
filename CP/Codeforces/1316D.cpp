#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

const int N = 1002;
const pii DIF[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n;
pii a[N][N], nxt[N][N];
queue<pii> q;

inline bool ValidCell(int i, int j) {
    return 0 < i && i <= n && 0 < j && j <= n;
}

void DFS(pii u, pii p) {
    nxt[u.fi][u.se] = p;
    for (int i = 0; i < 4; ++i) {
        pii v = {u.fi + DIF[i].fi, u.se + DIF[i].se};
        if (ValidCell(v.fi, v.se) && a[u.fi][u.se] == a[v.fi][v.se] && nxt[v.fi][v.se].fi < 0) {
            DFS(v, u);
        }
    }
}

void Solve1(int i, int j) {
    for (int t = 0; t < 4; ++t) {
        pii v = {i + DIF[t].fi, j + DIF[t].se};
        if (ValidCell(v.fi, v.se) && a[i][j] == a[v.fi][v.se]) {
            DFS(v, v);
            nxt[v.fi][v.se] = {i, j};
            nxt[i][j] = v;
            return;
        }
    }
    cout << "INVALID\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j].fi >> a[i][j].se;
    memset(nxt, -1, sizeof(nxt));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j].fi < 0) {
                Solve1(i, j);
            } else if (a[i][j] == pii(i, j)) {
                DFS(pii(i, j), pii(i, j));
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nxt[i][j].fi < 0) {
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    cout << "VALID\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nxt[i][j].fi == i - 1) {
                cout << "U";
            } else if (nxt[i][j].fi == i + 1) {
                cout << "D";
            } else if (nxt[i][j].se == j - 1) {
                cout << "L";
            } else if (nxt[i][j].se == j + 1) {
                cout << "R";
            } else {
                cout << "X";
            }
        }
        cout << "\n";
    }
    return 0;
}
