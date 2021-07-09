#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int n, a[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int d = a[1];
    for (int i = 2; i <= n; ++i) d = __gcd(d, a[i]);
    if (d != a[1])
    {
        cout << -1;
        return 0;
    }
    cout << n * 2 - 1 << "\n";
    cout << a[1] << " ";
    for (int i = 2; i <= n; ++i) cout << a[i] << " " << a[1] << " ";
    return 0;
}
