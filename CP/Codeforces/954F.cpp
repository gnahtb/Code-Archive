#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) % 2)
#define sqr(a) (a) * (a)
#define sz(a) int(a.size())

typedef long long ll;

struct TMatrix
{
    ll a[3][3];
    TMatrix() { memset(a, 0, sizeof a); }
    ll* operator [](int i) { return a[i]; }
};

const int maxN = 10005;
const ll mod = 1000000007;

int n, a[maxN], s[maxN * 2][3];
ll m, l[maxN], r[maxN];
vector<ll> u;
TMatrix ans;

TMatrix operator *(TMatrix &a, TMatrix &b)
{
    TMatrix c;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                (c[i][j] += a[i][k] * b[k][j] % mod) %= mod;
    return c;
}

TMatrix power(TMatrix a, ll b)
{
    if (b == 1) return a;
    TMatrix tmp = power(a, b / 2), ret = sqr(tmp);
    if (odd(b)) ret = ret * a;
    return ret;
}

int getIndex(ll x) { return lower_bound(u.begin(), u.end(), x) - u.begin(); }

void prep()
{
    memset(s, 0, sizeof s);
    for (int i = 0; i < n; ++i)
    {
        int p = getIndex(l[i]), q = getIndex(r[i] + 1);
        ++s[p][--a[i]]; --s[q][a[i]];
    }
    for (int i = 1; i < sz(u); ++i)
        for (int j = 0; j < 3; ++j) s[i][j] += s[i - 1][j];
}

void solve()
{
    ans.a[0][1] = 1;
    for (int k = 0; k < sz(u) - 1; ++k)
    {
        TMatrix cur;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cur[i][j] = s[k][j] == 0 && abs(i - j) < 2 ? 1 : 0;
        cur = power(cur, u[k + 1] - u[k] - (u[k] == 1));
        ans = ans * cur;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> l[i] >> r[i];
        u.push_back(l[i]); u.push_back(r[i] + 1);
        if (l[i] == 2) flag = false;
    }
    if (flag) u.push_back(1);
    u.push_back(m + 1);
    sort(u.begin(), u.end());
    u.resize(distance(u.begin(), unique(u.begin(), u.end())));
    prep();
    solve();
    cout << ans[0][1] << "\n";
    return 0;
}
