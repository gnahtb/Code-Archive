#include <bits/stdc++.h>

using namespace std;

int test, n;
string s;

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> s;
        string cur = s;
        int ans = 1;
        for (int k = 2; k <= n; ++k) {
            string t = "";
            if (k % 2 == n % 2) {
                for (int i = k - 1; i < n; ++i) t += s[i];
                for (int i = k - 2; i >= 0; --i) t += s[i];
            } else {
                for (int i = k - 1; i < n; ++i) t += s[i];
                for (int i = 0; i < k - 1; ++i) t += s[i];
            }
            if (cur > t) {
                cur = t;
                ans = k;
            }
        }
        cout << cur << "\n" << ans << "\n";
    }
    return 0;
}
