#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

int test, n, m;

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n >> m;
        int ans = 0, sum = 0;
        for (int i = 30; i >= 0; --i) {
            if (n >> i & 1) {
                if (sum + (1 << i) > m) break;
                sum += 1 << i;
            } else {
                if (sum + (1 << i) - 1 <= m) {
                    ans += 1 << i;
                    sum += 1 << i;
                }
            }
            // if (ans + (1 << i) - 1 <= m) {
            //     if ((n >> i & 1) == 0)
            //         ans += 1 << i;
            // } else {
                // if ((n >> i & 1) == 1)
                //     ans += 1 << i;
            // }
        }
        cout << ans << endl;
    }
    return 0;
}