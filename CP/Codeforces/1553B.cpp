#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

int q;
string s, t;

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> q;
    while (q--) {
        cin >> s >> t;
        bool ans = false;
        for (int i = 0; i <= sz(t); ++i) {
            string p1 = t.substr(0, i);
            string p2 = t.substr(i, sz(t) - i);
            for (int j = 0; j < sz(s); ++j) {
                bool flag = true;
                for (int k = 0; k < i; ++k) {
                    if (j + k >= sz(s) || s[j + k] != p1[k]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                for (int k = 0; k < sz(t) - i; ++k) {
                    if (j + i - 2 - k < 0 || s[j + i - 2 - k] != p2[k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = true;
                    break;
                }
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}