#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

typedef long long ll;

int n;
string s;
ll ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s += a ? 'X' : 'O';
    }
    while (sz(s) && s[0] == 'O') s.erase(0, 1);
    while (sz(s) && s[sz(s) - 1] == 'O') s.erase(sz(s) - 1, 1);
    if (!sz(s)) ans = 0;
    for (int l = 0, r = 1; l < sz(s); l = r++) {
        while (r < sz(s) && s[r]  == 'O') ++r;
        ans *= (r - l);
    }
    cout << ans << "\n";
    return 0;
}
