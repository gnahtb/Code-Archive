#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int n, q, a[N], cnt[N];
ll suma, sumcnt;
map<pair<int, int>, int> milestones;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        suma += a[i];
    }
    cin >> q;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u;
        int oldu = milestones[{s, t}];
        if (oldu > 0) {
            if (cnt[oldu] <= a[oldu]) {
                --sumcnt;
            }
            --cnt[oldu];
        }
        milestones[{s, t}] = u;
        if (u > 0) {
            ++cnt[u];
            if (cnt[u] <= a[u]) ++sumcnt;
        }
        ll ans = suma - sumcnt;
        cout << ans << "\n";
    }
    return 0;
}
