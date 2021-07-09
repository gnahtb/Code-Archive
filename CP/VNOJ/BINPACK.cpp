#include <bits/stdc++.h>

using namespace std;

int n, l, a[1000002];
pair<int, int> f[10002][5002];

void sub1() {
    int ans = INT_MAX;
    for (int m = 0; m < 1 << n; ++m) {
        int c1 = 0, c2 = 0, cur = 0;
        for (int i = 1; i <= n; ++i)
            if (m >> (i - 1) & 1) {
                if (c1 > l - a[i]) ++cur, c1 = a[i];
                else cur += !c1, c1 += a[i];
            } else {
                if (c2 > l - a[i]) ++cur, c2 = a[i];
                else cur += !c2, c2 += a[i];
            }
        ans = min(ans, cur);
    }
    cout << ans;
}

void sub2() {
    int tmp = 0, ans = 0;
    for (int i = 1, j = 1; i <= n; i = j) {
        int sum = 0;
        while (j <= n && sum < l) sum += a[j++];
        if (j > n) {
            if (sum > l) ++tmp;
            if (tmp > 0) ++ans;
            if (sum > 0) ++ans;
        } else {
            if (sum > l) ++tmp;
            if (tmp == l) ++ans, tmp = 0;
            ++ans;
        }
    }
    cout << ans;
}

void sub3() {
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= l; ++j)
            f[i][j] = make_pair(INT_MAX, INT_MAX);
    f[1][0] = make_pair(0, 0);
    for (int i = 1; i <= n; ++i) {
        for (int c1 = 0; c1 <= l; ++c1) if (f[i][c1].first < INT_MAX) {
            // add to cart 1
            if (c1 + a[i] > l) {
                f[i + 1][a[i]] = min(f[i + 1][a[i]], make_pair(f[i][c1].first + 1, f[i][c1].second));
            } else {
                f[i + 1][c1 + a[i]] = min(f[i + 1][c1 + a[i]], make_pair(f[i][c1].first + (c1 == 0), f[i][c1].second));
            }
            // add to cart 2
            if (f[i][c1].second + a[i] > l) {
                f[i + 1][c1] = min(f[i + 1][c1], make_pair(f[i][c1].first + 1, a[i]));
            } else {
                f[i + 1][c1] = min(f[i + 1][c1], make_pair(f[i][c1].first + (f[i][c1].second == 0), f[i][c1].second + a[i]));
            }
        }
    }
    int ans = INT_MAX;
    for (int j = 0; j <= l; ++j) ans = min(ans, f[n + 1][j].first);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> l >> n;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        if (b > 0) a[++j] = b;
    }
    n = j;
    if (n <= 20 && l > 5000) sub1();
    else if (n <= 10000 && l <= 5000) sub3();
    else sub2();
    return 0;
}