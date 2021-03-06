#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, m, a[N], b[N], c[N], pivota;

int bs(int x) {
    int l = 1, r = pivota, res = pivota + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x < a[mid]) {
            res = mid;
            r = mid - 1;
        } else if (x - a[mid] + 1 <= pivota - mid + 1) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int bs1(int x) {
    int l = pivota + 1, r = n, res = pivota;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x > a[mid]) {
            res = mid;
            l = mid + 1;
        } else if (a[mid] - x + 1 <= mid - pivota) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int bss(int x, int y) {
    int l = 1, r = m, res = y + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x <= b[mid]) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int bss1(int x, int y) {
    int l = 1, r = m, res = y - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x >= b[mid]) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

void solve() {
    for (int i = 1; i <= m; ++i)
        c[i] = c[i - 1] + binary_search(a + 1, a + n + 1, b[i]);
    pivota = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] < 0) pivota = i;
    int maxneg = 0, maxpos = 0;
    for (int i = 1; i <= m; ++i) {
        if (b[i] < 0) {
            int p = bs(b[i]);
            int t = pivota - p + 1;
            int q = bss(b[i] - t + 1, i);
            int t1 = i - q + 1;
            maxneg = max(maxneg, min(t1, t) + c[q - 1]);
        }
        if (b[i] > 0) {
            int p = bs1(b[i]);
            int t = p - pivota;
            int q = bss1(b[i] + t - 1, i);
            int t1 = q - i + 1;
            maxpos = max(maxpos, min(t1, t) + c[m] - c[q]);
        }
    }
    cout << (maxneg + maxpos) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= m; ++i) cin >> b[i];
        solve();
    }
    return 0;
}