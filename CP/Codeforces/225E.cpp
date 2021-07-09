/******************************************************************************
The answer are such x = power2(t) - 1 that power2(t + 1) - 1 is a prime number.
Those y = power2(t) - 1 is a prime number are called Mersenne primes.
The constant list below contains 40 Mersenne exponents (OEIS A000043).
******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1E9 + 7;
const int FALSE_EXP[40] = {2, 3, 5, 7, 13, 17, 19, 31, 61, 89,
                           107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423,
                           9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049,
                           216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011};

int n;
ll ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < FALSE_EXP[n - 1]; ++i) {
        (ans <<= 1LL) %= MOD;
    }
    (ans += MOD - 1) %= MOD;
    cout << ans << "\n";
    return 0;
}
