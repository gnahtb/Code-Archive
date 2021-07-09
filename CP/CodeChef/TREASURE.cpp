#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int Dirs = 4;
const int Di[Dirs] = {-1, 0, 1, 0};
const int Dj[Dirs] = {0, 1, 0, -1};

const int MOD = 1e9 + 7;
const int N = 32;

int test;
int n, m;
vector<bitset<N * N>> equas;

bool CheckCell(int i, int j) {
    return 0 < i && i <= n && 0 < j && j <= m;
}

int IDX(int i, int j) {
    return (i - 1) * m + j;
}

int Gauss() {
    int remains = n * m;
    for (int i = 0; i < sz(equas); ++i) {
        int p = -1;
        for (int j = 1; j <= n * m; ++j)
            if (equas[i][j] == 1) {
                p = j;
                break;
            }
        if (p < 0) {
            if (equas[i][n * m + 1] == 1) return -1;
            continue;
        }
        --remains;
        for (int j = 0; j < sz(equas); ++j) {
            if (i != j && equas[j][p] == 1) {
                equas[j] ^= equas[i];
            }
        }
    }
    return remains;
}

int main() {
    // freopen("inp.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> test;
    while (test--) {
        equas.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int a;
                cin >> a;
                if (a == -1) continue;
                bitset<N * N> equa;
                equa.reset();
                for (int k = 0; k < Dirs; ++k) {
                    int ti = i + Di[k], tj = j + Dj[k];
                    if (CheckCell(ti, tj)) equa[IDX(ti, tj)] = 1;
                }
                equa[n * m + 1] = a;
                equas.push_back(equa);
            }
        }
        int tmp = Gauss();
        int ans = 0;
        if (tmp >= 0) {
            ans = 1;
            for (int i = 0; i < tmp; ++i) (ans *= 2) %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}