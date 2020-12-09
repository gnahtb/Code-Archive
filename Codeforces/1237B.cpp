#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, a[N], b[N], ans;
bool chk[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1, j = 1; i <= n; ++i) {
        if (chk[a[i]]) continue;
        while (j <= n && a[i] != b[j]) {
            ++ans;
            chk[b[j]] = true;
            ++j;
        }
        ++j;
        chk[a[i]] = true;
    }
    cout << ans << "\n";
    return 0;
}
