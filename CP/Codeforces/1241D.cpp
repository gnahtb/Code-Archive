#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

typedef pair<int, int> pii;

const int N = 3e5 + 2;
const int oo = 1e9;

int q, n, a[N], l[N], r[N], f[N];
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    fill(l, l + N, oo);
    fill(r, r + N, -oo);
    cin >> q;
    while (q--) {
        v.clear();
        fill(l, l + n + 1, oo);
        fill(r, r + n + 1, -oo);
        fill(f, f + n + 1, 0);
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; ++i) {
            int t = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            l[t] = min(l[t], i);
            r[t] = max(r[t], i);
        }
        int ans = 1;
        f[0] = 1;
        for (int i = 1; i < sz(v); ++i) {
            if (l[i] > r[i - 1]) f[i] = f[i - 1] + 1;
            else f[i] = 1;
            ans = max(ans, f[i]);
        }
        ans = sz(v) - ans;
        cout << ans << "\n";
    }
    return 0;
}
