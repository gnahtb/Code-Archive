#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int t;

int main() {
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        char s[N];
        cin >> s;
        int n = strlen(s);
        for (int i = 0; i < n; ++i)
            if (s[i] == '0') --a;
            else if (s[i] == '1') --b;
        bool ok = true;
        for (int i = 0; i < n - i - 1; ++i) {
            if (s[i] != '?' && s[n - i - 1] != '?') {
                if (s[i] != s[n - i - 1]) {
                    ok = false;
                    break;
                }
            } else if (s[i] != '?' || s[n - i - 1] != '?') {
                if (s[i] != '?') s[n - i - 1] = s[i];
                else s[i] = s[n - i - 1];
                if (s[i] == '0') --a;
                else --b;
                if (a < 0 || b < 0) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            for (int i = 0; i < n - i - 1; ++i) {
                if (s[i] == '?') {
                    if (a > 1) {
                        s[i] = s[n - i - 1] = '0';
                        a -= 2;
                    } else if (b > 1) {
                        s[i] = s[n - i - 1] = '1';
                        b -= 2;
                    } else {
                        ok = false;
                        break;
                    }
                }
            }
            if (n % 2 != 0 && s[n / 2] == '?') {
                if (a > 0) s[n / 2] = '0', --a;
                else if (b > 0) s[n / 2] = '1', --b;
            }
            if (a > 0 || b > 0) ok = false;
            if (ok) cout << s << "\n";
            else cout << "-1\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}