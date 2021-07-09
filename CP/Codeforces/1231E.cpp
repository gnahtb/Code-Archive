#include <bits/stdc++.h>

using namespace std;

int q, n, fr[26];
string s, t;

int main() {
    cin >> q;
    while (q--) {
        int ans = INT_MAX;
        cin >> n >> s >> t;
        memset(fr, 0, sizeof fr);
        for (int i = 0; i < n; ++i) ++fr[s[i] - 'a'];
        for (int i = 0; i < n; ++i) --fr[t[i] - 'a'];
        bool flag = true;
        for (int i = 0; i < 26; ++i)
            if (fr[i] != 0) {
                flag = false;
                break;
            }
        if (!flag) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int c = i, tt = 0;
                for (int k = j; k <= n; ++k)
                    if (s[k - 1] == t[c - 1]) ++tt, ++c;
                ans = min(ans, n - tt);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
