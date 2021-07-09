#include <bits/stdc++.h>

using namespace std;

int n, ans[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 1) { cout << "1\n"; return 0; }
    int i = 1, x = n, t = 1, l = 0;
    while ((l + 1) * (l + 1) <= n) ++l;
    t = n / l;
    for (int j = 0; j < t; ++j) {
        int s = i;
        for (int j = 0; j < l; ++j) ans[i++] = x - j;
        reverse(ans + s, ans + i);
        x -= l;
    }
    if (i <= n) for (int j = 1; j <= x; ++j) ans[i++] = j;
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    return 0;
}
