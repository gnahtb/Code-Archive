#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
const int LIM = 1e5;

int n, q, a[N], p[LIM + 2], nxt[N][18], nxt1[N][18], f[LIM + 2];

void eratos() {
    for (int i = 2; i <= LIM; ++i) p[i] = i;
    for (int i = 2; i * i <= LIM; ++i) if (p[i] == i) {
        for (int j = i * i; j <= LIM; j += i) p[j] = i;
    }
}

vector<int> fact(int x) {
    vector<int> res;
    res.clear();
    while (x > 1) {
        int t = p[x];
        while (x % t == 0) x /= t;
        res.push_back(t);
    }
    return res;
}

int get_min(int l, int r) {
    int ld = __lg(r - l + 1);
    return min(nxt[l][ld], nxt[r - (1 << ld) + 1][ld]);
}

int main() {
    ios::sync_with_stdio(false);
    eratos();
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= LIM; ++i) f[i] = n + 1;
    for (int i = n; i; --i) {
        vector<int> pf = fact(a[i]);
        nxt[i][0] = n + 1;
        for (int j : pf) {
            nxt[i][0] = min(nxt[i][0], f[j]);
        }
        for (int j : pf) {
            f[j] = i;
        }
    }
    for (int j = 1; j < 18; ++j) {
        for (int i = 1; i <= n; ++i) {
            nxt[i][j] = nxt[i][j - 1];
            if (i + (1 << (j - 1)) <= n)
                nxt[i][j] = min(nxt[i][j], nxt[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (get_min(i, mid) <= mid) {
                r = mid - 1;
            } else {
                nxt1[i][0] = mid;
                l = mid + 1;
            }
        }
        ++nxt1[i][0];
    }
    for (int j = 1; j < 18; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (nxt1[i][j - 1] > n) {
                nxt1[i][j] = n + 1;
            } else {
                nxt1[i][j] = nxt1[nxt1[i][j - 1]][j - 1];
            }
        }
    }
    while (q--) {
        int l, r, ans = 1;
        cin >> l >> r;
        for (int j = 17; j >= 0; --j) {
            if (nxt1[l][j] <= r) {
                ans += 1 << j;
                l = nxt1[l][j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}