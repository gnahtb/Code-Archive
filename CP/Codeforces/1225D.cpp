#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

map<vector<pii>, int> mp;

const int LIM = 1e5 + 2;

int n, k, prm[LIM];
long long ans;

void erat() {
    int nmax = 1e5;
    for (int i = 2; i <= nmax; ++i) prm[i] = i;
    for (int i = 2; i * i <= nmax; ++i) if (prm[i] == i)
        for (int j = i * i; j <= nmax; j += i) prm[j] = i;
}

void fact(int x, vector<pii>& v) {
    v.clear();
    while (x > 1) {
        int tmp = prm[x], cnt = 0;
        while (x % tmp == 0) {
            x /= tmp;
            ++cnt;
        }
        cnt %= k;
        if (cnt != 0) v.emplace_back(tmp, cnt);
    }
    sort(v.begin(), v.end());
}

int main() {
    ios::sync_with_stdio(false);
    erat();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        vector<pii> vt, tg;
        fact(a, vt);
        tg.clear();
        for (pii i : vt) tg.emplace_back(i.fi, k - i.se);
        ans += mp[tg];
        ++mp[vt];
    }
    cout << ans << "\n";
    return 0;
}
