#include <cstdio>
#include <iostream>

using namespace std;

int x, y, a, b, c, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x >> y;
    a = b = c = y;
    while (a < x || b < x || c < x)
    {
        ++ans;
        if (ans % 3 == 1) a = min(x, b + c - 1);
        if (ans % 3 == 2) b = min(x, c + a - 1);
        if (ans % 3 == 0) c = min(x, a + b - 1);
    }
    cout << ans;
    return 0;
}
