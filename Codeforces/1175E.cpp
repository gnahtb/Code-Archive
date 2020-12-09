#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 1, L = 20;

int n, m, nx[N][L], ft[N][L];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        nx[l][0] = max(nx[l][0], r);
    }
    for (int i = 0; i < N; ++i) {
        if (i > 0)
            nx[i][0] = max(nx[i][0], nx[i - 1][0]);
        nx[i][0] = max(nx[i][0], i);
    }
    for (int j = 1; j < L; ++j)
        for (int i = 0; i < N; ++i)
            nx[i][j] = nx[nx[i][j - 1]][j - 1];
    for (int i = 0; i < N; ++i) {
        ft[i][0] = i;
        for (int j = 1; j < L; ++j)
            ft[i][j] = nx[ft[i][j - 1]][j - 1];
    }

    while (m--) {
        int x, y;
        cin >> x >> y;

        int ans = 0;
        for (int j = L - 1; j >= 0; --j) {
            if (ft[x][j] < y) {
                x = nx[x][j];
                ans += 1 << j;
            }
        }
        if (x < y) ans = -1;

        cout << ans << "\n";
    }

    return 0;
}
