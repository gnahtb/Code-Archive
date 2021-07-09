#include <bits/stdc++.h>

using namespace std;

int test;

int main() {
    freopen("collectingofficer.in", "r", stdin);
    cin >> test;
    while (test--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] - 'A' == cur) ++cur;
                if (cur == 26) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}