#include <cstdio>
#include <iostream>

using namespace std;

long long n, k, ans = 1;

int main()
{
    cin >> n >> k;
    if (k >= 2) ans += n*(n - 1)/2;
    if (k >= 3) ans += n*(n - 1)*(n - 2)/6 * 2;
    if (k >= 4) ans += n*(n - 1)*(n - 2)*(n - 3)/24 * 9;
    cout << ans;
    return 0;
}
