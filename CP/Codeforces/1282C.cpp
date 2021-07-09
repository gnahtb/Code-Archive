#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int test;
int n;
ll T, a, b;
pair<ll, int> p[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> test;
    while (test--) {
        int seasys = 0, shards = 0;
        cin >> n >> T >> a >> b;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i].second;
            if (p[i].second == 0) ++seasys;
            else ++shards;
        }
        for (int i = 1; i <= n; ++i) cin >> p[i].first;
        p[n + 1].first = T + 1;
        sort(p + 1, p + n + 1);
        int easys = 0, hards = 0;
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (i > 0) {
                if (p[i].second == 0) ++easys;
                else ++hards;
            }
            if (p[i + 1].first == p[i].first) continue;
            ll exp = a * easys + b * hards;
            if (exp >= p[i + 1].first) continue;
            int cur = easys + hards;
            ll rem = p[i + 1].first - 1 - exp;
            int reasys = seasys - easys;
            int rhards = shards - hards;
            if (reasys > 0) {
                ll tmp = rem / a;
                ll cando = min(tmp, 1LL * reasys);
                rem -= cando * a;
                cur += cando;
            }
            if (rhards > 0) {
                ll tmp = rem / b;
                ll cando = min(tmp, 1LL * rhards);
                rem -= cando * b;
                cur += cando;
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}
