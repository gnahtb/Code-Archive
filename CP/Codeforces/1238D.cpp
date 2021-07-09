#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 2;

int n, s[N], nx[N], nx1[N];
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        s[i] = c == 'B';
    }
    memset(nx, -1, sizeof nx);
    memset(nx1, -1, sizeof nx1);
    int t[2] = {-1};
    for (int i = 1; i <= n; ++i) {
        if (t[s[i]] > 0) nx[t[s[i]]] = i;
        t[s[i]] = i;
    }
    for (int l = 1, r = 1; r <= n; l = r) {
        while (r <= n && s[l] == s[r]) ++r;
        if (r > n) continue;
        for (int i = l; i < r; ++i) nx1[i] = r;
    }
    for (int i = 1; i <= n; ++i) {
        int tmp = n - i + 1;
        if (nx[i] < 0) continue;
        tmp -= nx[i] - i;
        if (nx[i] == i + 1) {
            if (nx1[i] >= 0) {
                --tmp;
            }
        }
        ans += tmp;
    }
    cout << ans << "\n";
    return 0;
}
