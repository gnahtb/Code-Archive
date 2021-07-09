#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int MAX = 1e5;

int prime[MAX + 2];
vector<int> dv[MAX + 2];

void Eratos() {
    for (int i = 2; i <= MAX; ++i) prime[i] = i;
    for (int i = 2; i * i <= MAX; ++i) if (prime[i] == i)
        for (int j = i * i; j <= MAX; j += i) prime[j] = i;
}

vector<pair<int, int>> vp;
void GetDivs(int cur, int lim, int i, vector<int>& vt) {
    if (i > sz(vp)) {
        if (1LL * lim * lim / cur <= MAX) vt.push_back(cur);
        return;
    }
    for (int it = 0; it <= vp[i - 1].second; ++it) {
        GetDivs(cur, lim, i + 1, vt);
        if (1LL * cur * vp[i - 1].first > lim) return;
        cur *= vp[i - 1].first;
    }
}

void Prep() {
    for (int i = 1; i <= MAX; ++i) {
        vp.clear();
        int x = i;
        while (x > 1) {
            int tmp = prime[x], pw = 0;
            while (x % tmp == 0) x /= tmp, ++pw;
            vp.emplace_back(tmp, pw * 2);
        }
        GetDivs(1, i, 1, dv[i]);
    }
}

void Print() {
    for (int i = 1; i <= MAX; ++i) {
        cout << i << " = ";
        for (int j : dv[i]) cout << j << " ";
        cout << "\n";
    }
}

int test, n, m;
bool negx[MAX + 2], posx[MAX + 2], negy[MAX + 2], posy[MAX + 2];

void Reset() {
    memset(negx, false, sizeof(negx));
    memset(posx, false, sizeof(posx));
    memset(negy, false, sizeof(negy));
    memset(posy, false, sizeof(posy));
}

int Solve(bool flag[], bool pos[], bool neg[]) {
    int ret = 0;
    for (int i = 1; i <= MAX; ++i) if (flag[i]) {
        for (int j : dv[i]) {
            ret += pos[j] && neg[1LL * i * i / j];
            if (i != j) ret += neg[j] && pos[1LL * i * i / j];
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Eratos();
    Prep();
    cin >> test;
    while (test--) {
        Reset();
        cin >> n >> m;
        int senx = 0, seny = 0;
        for (int i = 1, t; i <= n; ++i) {
            cin >> t;
            if (t < 0) negx[-t] = true;
            else if (t > 0) posx[t] = true;
            else ++senx;
        }
        for (int i = 1, t; i <= m; ++i) {
            cin >> t;
            if (t < 0) negy[-t] = true;
            else if (t > 0) posy[t] = true;
            else ++seny;
        }
        long long ans = 0;
        ans += Solve(posx, posy, negy);
        ans += Solve(negx, posy, negy);
        ans += Solve(posy, posx, negx);
        ans += Solve(negy, posx, negx);
        ans += 1LL * (senx + seny) * (n - senx) * (m - seny);
        cout << ans << "\n";
    }
    return 0;
}