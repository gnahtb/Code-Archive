#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()
#define sqr(a) ((a) * (a))

const int LIM = 205;

int n;
char a[LIM];

int ans[LIM][LIM];
vector<int> f[LIM][LIM];

void solve() {
    for (int i = 0; i < n; ++i) {
        f[i][i].assign(1, 1);
        ans[i][i] = 1;
    }
    for (int d = 1; d < n; ++d)
        for (int l = 0, r = d; r < n; ++l, ++r) {
            int cnt = 0;
            for (int i = l; i <= r; ++i) cnt += a[i] == a[r];
            f[l][r].assign(cnt, 0);
            f[l][r][0] = 1;
            for (int i = l; i < r; ++i) if (a[i] == a[r])
                for (int j = 0; j < sz(f[l][i]); ++j) {
                    int tmp = f[l][i][j] + ans[i + 1][r - 1] + sqr(j + 2) - sqr(j + 1);
                    f[l][r][j + 1] = max(f[l][r][j + 1], tmp);
                }
            for (int i = l; i <= r; ++i) {
                for (int j = 0; j < sz(f[l][i]); ++j) {
                    int tmp = f[l][i][j] + ans[i + 1][r];
                    ans[l][r] = max(ans[l][r], tmp);
                }
            }
        }
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d\n%s", &n, &a);
    solve();
    printf("%d\n", ans[0][n - 1]);
    return 0;
}