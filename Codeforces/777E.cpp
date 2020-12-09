#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct TRing { ll inner, outer, height; };

const int N_MAX = 1E5 + 5;

int n;
TRing a[N_MAX];
ll f[N_MAX], ans = 0;
stack<int> s;

void prep() {
    int l = 1, r = 1, t = n;
    for (n = 0; l <= t; l = r) {
        ll new_inner = INT_MAX, new_height = 0;
        while (r <= t && a[l].outer == a[r].outer) ++r;
        for (int i = l; i < r; ++i) {
            new_inner = min(new_inner, a[i].inner);
            new_height += a[i].height;
        }
        a[++n] = {new_inner, a[l].outer, new_height};
    }
}

void solve() {
    memset(f, 0, sizeof f);
    s.push(0);
    for (int i = 1; i <= n; ++i) {
        while (a[s.top()].inner >= a[i].outer) s.pop();
        f[i] = f[s.top()] + a[i].height;
        ans = max(ans, f[i]);
        s.push(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].inner >> a[i].outer >> a[i].height;
    sort(a + 1, a + n + 1, [](TRing &l, TRing &r) {
        return l.outer > r.outer;
    });
    prep();
    solve();
    cout << ans << "\n";
    return 0;
}
