#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 2;

int n, k, p[N], c[N], id[N];
ll cur, ans[N];
priority_queue<int, vector<int>, greater<int>> h;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> p[i], id[i] = i;
    for (int i = 1; i <= n; ++i) cin >> c[i], ans[i] = c[i];

    sort(id + 1, id + n + 1, [](int x, int y) { return p[x] < p[y]; });
    for (int l = 1, r = 1; l <= n; l = r) {
        while (r <= n && p[l] == p[r]) ++r;
        for (int i = l; i < r; ++i) ans[id[i]] += cur;
        for (int i = l; i < r; ++i) {
            if (h.size() < k) {
                h.push(c[id[i]]);
                cur += c[id[i]];
                continue;
            }
            if (k == 0) continue;
            if (h.top() < c[id[i]]) {
                cur -= h.top();
                h.pop();
                h.push(c[id[i]]);
                cur += c[id[i]];
            }
        }
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";

    return 0;
}
