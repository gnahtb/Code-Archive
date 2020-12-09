#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll l, r;

ll get_bit(ll state, ll index) { return (state >> index) & 1; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> l >> r;
    if (l < r)
    {
        ll t = log2(r);
        for (; t >= 0; --t)
            if (get_bit(l, t) + get_bit(r, t) == 1) break;
        cout << ((ll)1 << (t + 1)) - 1;
    }
    else cout << 0;
    return 0;
}
