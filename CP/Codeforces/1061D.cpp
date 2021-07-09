#include <bits/stdc++.h>

using namespace std;

#define long long long
#define fi first
#define se second
#define sz(a) (int)a.size()

typedef pair<int, int> ii;

const int N_MAX = 1e5 + 5;
const long MOD = 1e9 + 7;

int n, x, y, cnt[N_MAX << 1], lim[N_MAX << 1], b[N_MAX << 1];
long ans = 0;
vector<int> t;
ii a[N_MAX];
deque<int> dq;

inline int id(int x) {
    return lower_bound(t.begin(), t.end(), x) - t.begin();
}

void prep() {
    int pivot = x / y;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) ++cnt[id(a[i].fi)], --cnt[id(a[i].se + 1)];
    for (int i = 1; i < sz(t); ++i) cnt[i] += cnt[i - 1];
    for (int l = 0, r = 0; l < sz(t); ++l) {
        while (!dq.empty() && dq.front() < l) dq.pop_front();
        for (; r < sz(t) && t[r] - t[l] < pivot; ++r) {
            while (!dq.empty() && cnt[dq.back()] <= cnt[r]) dq.pop_back();
            dq.push_back(r);
        }
        lim[l] = cnt[dq.front()];
    }
}

void solve() {
    b[0] = cnt[0];
    ans = (long)cnt[0] * x;
    for (int i = 1; i < sz(t); ++i) {
        (ans += (long)(t[i] - t[i - 1] - 1) * y % MOD * b[i - 1] % MOD) %= MOD;
        b[i] = b[i - 1] <= cnt[i] ? cnt[i] : min(b[i - 1], lim[i]);
        (ans += (long)max(0, b[i] - b[i - 1]) * x % MOD + (long)min(b[i], b[i - 1]) * y % MOD) %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi >> a[i].se;
        t.push_back(a[i].fi);
        t.push_back(a[i].se + 1);
    }
    sort(t.begin(), t.end());
    t.resize(distance(t.begin(), unique(t.begin(), t.end())));
    prep();
    solve();
    cout << ans << "\n";
    return 0;
}
