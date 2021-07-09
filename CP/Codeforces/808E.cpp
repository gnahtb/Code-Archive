#include <bits/stdc++.h>
#define long long long
using namespace std;

const long maxN = 1e5+5;
const long maxM = 3e5+5;

long n, m, c[5][maxN], sz[5], pref[5][maxN], f[maxM], g[5][maxM];

void enter() {
    memset(c, 0, sizeof(c));
    memset(sz, 0, sizeof(sz));
    cin >> n >> m;
    for (long i = 1; i <= n; ++i) {
        long cost, weight;
        cin >> weight >> cost;
        c[weight][++sz[weight]] = cost;
    }
}

void init() {
    memset(pref, 0, sizeof(pref));
    for (long j = 1; j <= 3; ++j) {
        sort(c[j]+1, c[j]+sz[j]+1, greater<long>());
        for (long i = 1; i <= sz[j]; ++i)
            pref[j][i] = pref[j][i-1]+c[j][i];
    }
}

void prep() {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (long i = 1; i <= m; ++i) {
        long sumMax = 0;
        for (long j = 1; j < 3; ++j)
            if (i >= j) {
                long tmp[5];
                tmp[1] = g[1][i-j];
                tmp[2] = g[2][i-j];
                if (tmp[j] < sz[j]) ++tmp[j];
                long cur = pref[1][tmp[1]]+pref[2][tmp[2]];
                if (sumMax < cur) {
                    sumMax = cur;
                    g[1][i] = tmp[1];
                    g[2][i] = tmp[2];
                }
            }
        f[i] = sumMax;
    }
}

main() {
    ios_base::sync_with_stdio(false);
    enter();
    init();
    prep();
    long ans = 0;
    for (long i = 0; i <= m/3; ++i) {
        long tmp = pref[3][i]+f[m-i*3];
        ans = max(ans, tmp);
    }
    cout << ans;
}
