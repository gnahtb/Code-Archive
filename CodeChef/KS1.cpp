#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

typedef long long ll;

const int N = 1e5 + 2;

int t;
int n;
pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(false);
    scanf("%d", &t);
    while (t--) {
        ll ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].first);
            a[i].first ^= a[i - 1].first;
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        for (int l = 0, r = 0; l <= n; l = r) {
            while (r <= n && a[l].first == a[r].first) ++r;
            ll cs = 0;
            for (int i = l; i < r; cs += a[i++].second) {
                ll tmp = 1LL * (a[i].second - 1) * (i - l) - cs;
                ans += tmp;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}