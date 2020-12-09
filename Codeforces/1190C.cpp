#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

struct IT {
    struct Node {
        int lf, rg;
        int mn = oo, mx = -oo;
        int lz = 0;
    };
    vector<Node> a;

    void init(int n) {
        a.clear();
        a.resize((n << 2) + 2);
    }

#define md ((l + r) >> 1)
#define nx (i << 1)
    void down(int i) {
        a[i].mn += a[i].lz;
        a[i].mx += a[i].lz;
        if (a[i].lf < a[i].rg) {
            a[nx].lz += a[i].lz;
            a[nx + 1].lz += a[i].lz;
        }
        a[i].lz = 0;
    }

    void build(int l, int r, int i = 1) {
        a[i].lf = l;
        a[i].rg = r;
        if (l == r) return;
        build(l, md, nx);
        build(md + 1, r, nx + 1);
    }

    void mod(int p, int x, int i = 1) {
        down(i);
        if (a[i].lf > p || a[i].rg < p) return;
        if (a[i].lf == p && a[i].rg == p) {
            a[i].mn = a[i].mx = x;
            a[i].lz = 0;
            return;
        }
        mod(p, x, nx);
        mod(p, x, nx + 1);
        a[i].mn = min(a[nx].mn, a[nx + 1].mn);
        a[i].mx = max(a[nx].mx, a[nx + 1].mx);
    }

    void inc(int l, int r, int d, int i = 1) {
        if (l > r) return;
        if (a[i].lf > r || a[i].rg < l) return;
        if (l <= a[i].lf && a[i].rg <= r) {
            a[i].lz += d;
            down(i);
            return;
        }
        down(i);
        inc(l, r, d, nx);
        inc(l, r, d, nx + 1);
        a[i].mn = min(a[nx].mn, a[nx + 1].mn);
        a[i].mx = max(a[nx].mx, a[nx + 1].mx);
    }

    int fmax(int l, int r, int i = 1) {
        if (a[i].lf > r || a[i].rg < l) return -oo;
        down(i);
        if (l <= a[i].lf && a[i].rg <= r) return a[i].mx;
        return max(fmax(l, r, nx), fmax(l, r, nx + 1));
    }

    int fmin(int l, int r, int i = 1) {
        if (a[i].lf > r || a[i].rg < l) return oo;
        down(i);
        if (l <= a[i].lf && a[i].rg <= r) return a[i].mn;
        return min(fmin(l, r, nx), fmin(l, r, nx + 1));
    }
#undef md
#undef nx
} itree;

void stop(string ans) {
    cout << ans << "\n";
    exit(0);
}

const int N = 1e5 + 2;

int n, k, a[N], pf[N];

void solvepre() {
    for (int l = 1, r = k; r <= n; ++l, ++r) {
        int tmp = pf[n] - pf[r] + pf[l - 1];
        if (tmp == 0 || tmp == n - k)
            stop("tokitsukaze");
    }
}

void solve0() {
    for (int i = 1; i + k - 1 <= n; ++i)
        itree.mod(i, pf[i + k - 1] - pf[i - 1]);
    for (int l = 2 - k, r = 1; r <= n; ++l, ++r) {
        if (l > 1) itree.inc(max(l - k, 1), l - 1, a[l - 1]);
        itree.inc(l, r, -a[r]);
        int sum = pf[n] - pf[r] + pf[max(0, l - 1)];
        int cmx = itree.fmax(1, n - k + 1);
        int cmn = itree.fmin(1, n - k + 1);
        // printf("sum = %d | cmn = %d | cmx = %d\n", sum, cmn, cmx);
        if (l > 0 && sum - cmn != n - k && sum - cmx != 0) {
            stop("once again");
        }
    }
    printf("\n");
}

void solve1() {
    for (int i = 1; i + k - 1 <= n; ++i)
        itree.mod(i, pf[i + k - 1] - pf[i - 1]);
    for (int l = 2 - k, r = 1; r <= n; ++l, ++r) {
        if (l > 1) itree.inc(max(l - k, 1), l - 1, -(a[l - 1] ^ 1));
        itree.inc(l, r, a[r] ^ 1);
        int sum = pf[n] - pf[r] + pf[max(0, l - 1)] + r - max(l, 1) + 1;
        int cmx = itree.fmax(1, n - k + 1);
        int cmn = itree.fmin(1, n - k + 1);
        // printf("sum = %d | cmn = %d | cmx = %d\n", sum, cmn, cmx);
        if (l > 0 && sum - cmn != n - k && sum - cmx != 0) {
            stop("once again");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        char ch;
        cin >> ch;
        a[i] = ch - '0';
        pf[i] = pf[i - 1] + a[i];
    }
    solvepre();
    itree.init(n - k + 1);
    itree.build(1, n - k + 1);
    solve0();
    solve1();
    stop("quailty");
    return 0;
}
