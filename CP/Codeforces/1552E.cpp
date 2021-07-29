#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 102, K = 102;

int n, k;
vector<int> c[N], ids;
pair<int, int> seg[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n * k; ++i) {
        int t;
        cin >> t;
        c[t].push_back(i);
    }
    for (int i = 1; i <= n; ++i) ids.push_back(i);
    int t = 1;
    int st = 0;
    int limit = (n + k - 2) / (k - 1);
    while (st < sz(ids)) {
        sort(ids.begin() + st, ids.end(), [&](int x, int y) {
            return c[x][t] < c[y][t];
        });
        for (int i = st; i < min(st + limit, sz(ids)); ++i)
            seg[ids[i]] = make_pair(c[ids[i]][t - 1], c[ids[i]][t]);
        st += limit;
        ++t;
    }
    for (int i = 1; i <= n; ++i)
        cout << seg[i].first << " " << seg[i].second << endl;
    return 0;
}