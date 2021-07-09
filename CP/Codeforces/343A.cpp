#include <cstdio>
#include <iostream>

using namespace std;

#define long long long

long a, b, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    while (a)
    {
        long t = a / b;
        if (t)
        {
            ans += t;
            a = a % b;
        }
        else
        {
            ans += 1;
            swap(a, b);
            a -= b;
        }
    }
    cout << ans;
    return 0;
}
