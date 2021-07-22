#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 1e5 + 2;

int q;
string s, t;

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> q;
    while (q--) {
        cin >> s >> t;
        int d = sz(s) - sz(t);
        int x = -1;
        for (int i = 0; i < sz(s); ++i)
            if (d % 2 == i % 2 && s[i] == t[0]) {
                x = i;
                break;
            }
        if (x < 0) {
            cout << "NO\n";
            continue;
        }
        ++x;
        bool ans = true;
        for (int i = 1; i < sz(t); ++i) {
            while (x < sz(s) && s[x] != t[i]) x += 2;
            if (x >= sz(s)) {
                ans = false;
                break;
            }
            ++x;
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}