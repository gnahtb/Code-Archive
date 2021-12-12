#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int test, n, a[N];

int main() {
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int cur = a[n];
        int ans = 0;
        for (int i = n - 1; i > 0; --i) {
            if (a[i] > cur) {
                cur = a[i];
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}