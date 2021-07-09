#include <bits/stdc++.h>

using namespace std;

int t;
int n, a, b, c;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c >> s;
        int cnt = 0;
        int a1 = 0, b1 = 0, c1 = 0;
        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') ++a1;
            else if (s[i] == 'P') ++b1;
            else ++c1;
            ans += '?';
        }
        a1 = min(a1, b);
        b1 = min(b1, c);
        c1 = min(c1, a);
        cnt = a1 + b1 + c1;
        if (cnt < (n + 1) / 2) {
            cout << "NO\n";
            continue;
        }
        a -= c1;
        b -= a1;
        c -= b1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R' && a1 > 0) {
                --a1;
                ans[i] = 'P';
            }
            if (s[i] == 'P' && b1 > 0) {
                --b1;
                ans[i] = 'S';
            }
            if (s[i] == 'S' && c1 > 0) {
                --c1;
                ans[i] = 'R';
            }
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] == '?') {
                if (a > 0) {
                    --a;
                    ans[i] = 'R';
                } else if (b > 0) {
                    --b;
                    ans[i] = 'P';
                } else {
                    --c;
                    ans[i] = 'S';
                }
            }
        }
        cout << "YES\n" << ans << "\n";
    }
    return 0;
}
