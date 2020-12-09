#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

int t;
string s;

void solve() {
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != '1') continue;
        s[i] = '#';
        if (i < sz(s) - 1) {
            if (s[i + 1] == '0') s[i + 1] = '1';
            else s[i + 1] = '0';
        }
        for (int j = i - 1; j >= 0; --j)
            if (s[j] == '0') s[j] = '#';
            else break;
    }
    for (int i = 0; i < sz(s); ++i)
        if (s[i] != '#') {
            cout << "LOSE\n";
            return;
        }
    cout << "WIN\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> s;
        solve();
    }
    return 0;
}