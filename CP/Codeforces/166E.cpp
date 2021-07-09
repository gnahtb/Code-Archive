#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)
#define sqr(a) (a) * (a)

typedef long long ll;

struct TMatrix
{
    ll a[4][4];
    TMatrix() { memset(a, 0, sizeof a); }
    ll* operator [](int i) { return a[i]; }
};

const ll mod = 1E9 + 7;

int n;
TMatrix ans;

TMatrix operator *(TMatrix &a, TMatrix &b)
{
    TMatrix c;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                (c[i][j] += a[i][k] * b[k][j] % mod) %= mod;
    return c;
}

TMatrix power(TMatrix a, int b)
{
    if (b == 1) return a;
    TMatrix tmp = power(a, b >> 1), ret = sqr(tmp);
    if (odd(b)) ret = ret * a;
    return ret;
}

void solve()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) ans[i][j] = i == j ? 0 : 1;
    ans = power(ans, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    solve();
    printf("%lld\n", ans[3][3]);
    return 0;
}
