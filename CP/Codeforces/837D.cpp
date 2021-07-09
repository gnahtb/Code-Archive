#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define long long long
#define fill(a, b) memset(a, b, sizeof a);

const int inf = 60000;

int n, k, f[205][12805];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    fill(f, -inf);
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        long a;
        cin >> a;
        int pw2 = 0, pw5 = 0;
        while (a%2 == 0) ++pw2, a /= 2;
        while (a%5 == 0) ++pw5, a /= 5;
        for (int j = k; j > 0; --j)
            for (int p = pw2; p <= 12800; ++p)
                if (f[j - 1][p - pw2] > -inf)
                    f[j][p] = max(f[j][p], f[j - 1][p - pw2] + pw5);
    }
    int ans = 0;
    for (int i = 1; i <= 12800; ++i)
        ans = max(ans, min(i, f[k][i]));
    cout << ans;
}
