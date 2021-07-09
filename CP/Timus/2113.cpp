#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define R first
#define C second

const int N = 102;
const int oo = 0x3f3f3f3f;
const pii d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m, h[N][N];
pii rabbit, water;
int dwater[N][N], drabbit[N][N];
queue<pii> q;

bool Check(pii x) {
    return 0 < x.R && x.R <= n && 0 < x.C && x.C <= m;
}

void BFS(pii start, int dif, int (&dis)[N][N], int (&comp)[N][N]) {
    memset(dis, -1, sizeof(dis));
    q.push(start);
    dis[start.R][start.C] = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            pii nxt = {cur.R + d[i].R, cur.C + d[i].C};
            if (!Check(nxt)) continue;
            if (dis[nxt.R][nxt.C] >= 0) continue;
            if (h[nxt.R][nxt.C] - h[cur.R][cur.C] > dif) continue;
            if (comp[nxt.R][nxt.C] >= 0 && dis[cur.R][cur.C] + 1 >= comp[nxt.R][nxt.C]) continue;
            q.push(nxt);
            dis[nxt.R][nxt.C] = dis[cur.R][cur.C] + 1;
        }
    }
}

bool F() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (drabbit[i][j] >= 0 && dwater[i][j] < 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> h[i][j];
    cin >> rabbit.R >> rabbit.C;
    cin >> water.R >> water.C;
    memset(drabbit, oo, sizeof(drabbit));
    BFS(water, 0, dwater, drabbit);
    int lf = 0, rg = oo, ans = -1;
    while (lf <= rg) {
        int md = (lf + rg) / 2;
        BFS(rabbit, md, drabbit, dwater);
        if (F()) {
            ans = md;
            rg = md - 1;
        } else {
            lf = md + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}