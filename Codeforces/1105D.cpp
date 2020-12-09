#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1002, M = 1002;
const int P = 10;
 
const int DCnt = 4;
const int Di[DCnt] = {-1, 0, 1, 0};
const int Dj[DCnt] = {0, 1, 0, -1};
 
int n, m, p, ans[P];
long long s[P], dmx[P], dis[N][M];
bool ok[N][M];
 
int cc;
queue<pair<int, int>> q[P];
 
void solve() {
    for (int k = 1; cc > 0; ++(k %= p)) {
        if (q[k].empty()) continue;
        dmx[k] += s[k];
        while (!q[k].empty()) {
            int i = q[k].front().first;
            int j = q[k].front().second;
            if (dis[i][j] == dmx[k]) break;
            q[k].pop(); --cc;
            for (int t = 0; t < DCnt; ++t) {
                int ni = i + Di[t];
                int nj = j + Dj[t];
                if (!ok[ni][nj] || dis[ni][nj] >= 0) continue;
                ++ans[k];
                ++cc;
                dis[ni][nj] = dis[i][j] + 1;
                q[k].emplace(ni, nj);
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    memset(dis, -1, sizeof dis);
    cin >> n >> m >> p;
    for (int i = 1; i <= p; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c != '#') {
                ok[i][j] = true;
                if ('1' <= c && c <= '9') {
                    q[c - '0'].emplace(i, j);
                    dis[i][j] = 0;
                    ++ans[c - '0'];
                    ++cc;
                }
            }
        }
    solve();
    for (int k = 1; k <= p; ++k)
        cout << ans[k] << " ";
    return 0;
}
