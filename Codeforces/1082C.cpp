#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int M_MAX = 1e5 + 5;

int n, m, ans = 0, id[M_MAX], cur[M_MAX];
vector<int> a[M_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int s, r;
        cin >> s >> r;
        a[s].push_back(r);
    }
    for (int i = 1; i <= m; ++i) {
        sort(a[i].begin(), a[i].end(), greater<int>());
        id[i] = i;
    }
    sort(id + 1, id + m + 1, [](int x, int y) {
        return sz(a[x]) > sz(a[y]);
    });
    memset(cur, 0, sizeof cur);
    int pivot = m;
    for (int x = 1; x <= n; ++x) {
        while (pivot > 0 && sz(a[id[pivot]]) < x) --pivot;
        if (pivot == 0) break;
        int tmp = 0;
        for (int i = 1; i <= pivot; ++i) cur[id[i]] += a[id[i]][x - 1];
        for (int i = 1; i <= pivot; ++i) if (cur[id[i]] > 0) tmp += cur[id[i]];
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}
