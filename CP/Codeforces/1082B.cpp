#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define sz(a) (int)a.size()

typedef pair<int, int> ii;

int n, g = 0, ans = 0;
string s;
vector<ii> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && s[l] == s[r]) ++r;
        a.push_back({r - l, s[l] == 'G' ? 0 : 1});
        if (s[l] == 'G') ans = max(ans, r - l), ++g;
    }
    if (g == 1) {
        cout << ans << "\n";
        return 0;
    }
    for (int i = 0; i < sz(a); ++i) if (a[i].se == 0) {
        if (i > 0) {
            if (a[i - 1].fi == 1) {
                if (i == 1) {
                    if (g > 1) ans = max(ans, a[i].fi + 1);
                } else {
                    if (g > 2) ans = max(ans, a[i].fi + a[i - 2].fi + 1);
                    else ans = max(ans, a[i].fi + a[i - 2].fi);
                }
            } else {
                if (g > 1) ans = max(ans, a[i].fi + 1);
            }
        }
        if (i < sz(a) - 1) {
            if (a[i + 1].fi == 1) {
                if (i == sz(a) - 1) {
                    if (g > 1) ans = max(ans, a[i].fi + 1);
                } else {
                    if (g > 2) ans = max(ans, a[i].fi + a[i + 2].fi + 1);
                    else ans = max(ans, a[i].fi + a[i + 2].fi);
                }
            } else {
                if (g > 1) ans = max(ans, a[i].fi + 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
