#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, a[2005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (count(a + 1, a + n + 1, 1) > 0)
    {
        cout << n - count(a + 1, a + n + 1, 1);
        return 0;
    }
    int ans = INFINITY;
    for(int i = 1; i <= n; i++)
    {
        int g = a[i];
        for (int j = i; j <= n; j++)
        {
            g = __gcd(g, a[j]);
            if(g == 1) ans = min(ans, j - i);
        }
    }
    if (ans > 1e5) cout << -1;
    else cout << ans + n - 1;
    return 0;
}
