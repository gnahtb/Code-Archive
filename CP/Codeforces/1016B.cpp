#include <iostream>
#include <string>

using namespace std;

#define sz(a) (int)a.size()

const int N = 1005;

int n, m, q, c[N];
string s, t;

int check(int x) {
    for (int i = 0; i < sz(t); ++i)
        if (s[x + i] != t[i]) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q >> s >> t;
    for (int i = 1; i <= sz(s); ++i)
        c[i] = c[i - 1] + (i + sz(t) - 1 <= sz(s) ? check(i - 1) : 0);
    while (q--) {
        int l, r, ans = 0;
        cin >> l >> r;
        if (r - l + 1 >= sz(t)) ans = c[r - sz(t) + 1] - c[l - 1];
        cout << ans << "\n";
    }
    return 0;
}
