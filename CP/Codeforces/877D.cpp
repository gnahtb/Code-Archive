#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

const int N = 1002;

int n, m, k, dist[N][N];
char c[N][N];
set<int> row[N], col[N];
pii start, finish;
queue<pii> q;
queue<int> del;

// 0 -> up
// 1 -> down
// 2 -> left
// 3 -> right
int ncan[N][N][4];

istream& operator>>(istream& in, pair<int, int>& p) {
    in >> p.first >> p.second;
    return in;
}

void Prep() {
    memset(ncan, -1, sizeof(ncan));
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) if (c[i][j] == '.') {
            ncan[i][j][0] = ncan[i - 1][j][0] > 0 ? ncan[i - 1][j][0] : i;
        }
        for (int i = n; i; --i) if (c[i][j] == '.') {
            ncan[i][j][1] = ncan[i + 1][j][1] > 0 ? ncan[i + 1][j][1] : i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) if (c[i][j] == '.') {
            ncan[i][j][2] = ncan[i][j - 1][2] > 0 ? ncan[i][j - 1][2] : j;
        }
        for (int j = m; j; --j) if (c[i][j] == '.') {
            ncan[i][j][3] = ncan[i][j + 1][3] > 0 ? ncan[i][j + 1][3] : j;
        }
    }
}

void SetErase(int t, set<int>& s) {
    set<int>::iterator it = s.find(t);
    if (it == s.end()) return;
    s.erase(it);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c[i][j];
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    cin >> start >> finish;
    Prep();
    memset(dist, -1, sizeof(dist));
    dist[start.X][start.Y] = 0;
    SetErase(start.Y, row[start.X]);
    SetErase(start.X, col[start.Y]);
    q.push(start);
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        if (u == finish) break;
        int l = max(u.X - k, ncan[u.X][u.Y][0]);
        int r = min(u.X + k, ncan[u.X][u.Y][1]);
        set<int>::iterator itl = col[u.Y].lower_bound(l);
        set<int>::iterator itr = col[u.Y].upper_bound(r);
        for (set<int>::iterator it = itl; it != itr; ++it) {
            dist[*it][u.Y] = dist[u.X][u.Y] + 1;
            q.emplace(*it, u.Y);
            del.push(*it);
        }
        while (!del.empty()) {
            SetErase(del.front(), col[u.Y]);
            SetErase(u.Y, row[del.front()]);
            del.pop();
        }
        l = max(u.Y - k, ncan[u.X][u.Y][2]);
        r = min(u.Y + k, ncan[u.X][u.Y][3]);
        itl = row[u.X].lower_bound(l);
        itr = row[u.X].upper_bound(r);
        for (set<int>::iterator it = itl; it != itr; ++it) {
            dist[u.X][*it] = dist[u.X][u.Y] + 1;
            q.emplace(u.X, *it);
            del.push(*it);
        }
        while (!del.empty()) {
            SetErase(del.front(), row[u.X]);
            SetErase(u.X, col[del.front()]);
            del.pop();
        }
    }
    cout << dist[finish.X][finish.Y] << "\n";
    return 0;
}
