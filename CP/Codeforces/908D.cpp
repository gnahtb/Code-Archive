#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll Pow(ll x, ll y, ll z) {
    if (y == 0) return 1 % z;
    ll t = Pow(x, y >> 1, z);
    (t *= t) %= z;
    if ((y & 1) != 0) (t *= x) %= z;
    return t;
}

const ll MOD = 1e9 + 7;
const int LIM = 4000;

int k;
ll pa, pb, a, b, f[LIM][LIM];

ll Solve(int i, int j) {
    if (f[i][j] >= 0) goto ret;
    if (j >= k) return 0;
    if (i + j >= k) {
        // f[i][j] = (j + i) * b % MOD * ai % MOD * bi % MOD;
        f[i][j] = (i + j + pa * Pow(pb, MOD - 2, MOD) % MOD) % MOD;
    } else {
        f[i][j] = a * Solve(i + 1, j) % MOD;
        (f[i][j] += b * Solve(i, i + j)) %= MOD;
    }
ret:
    return f[i][j];
}

// void Print() {
//     printf("a = %lld; b = %lld\n", a, b);
//     printf("ai = %lld; bi = %lld\n", ai, bi);
//     for (int i = 0; i <= 5; ++i) {
//         for (int j = 0; j <= 5; ++j) {
//             printf("f[%d][%d] = %lld\n", i, j, f[i][j]);
//         }
//     }
// }

int main() {
    // freopen("out.txt", "w", stdout);
    cin >> k >> pa >> pb;
    a = pa * Pow(pa + pb, MOD - 2, MOD) % MOD;
    b = pb * Pow(pa + pb, MOD - 2, MOD) % MOD;
    memset(f, -1, sizeof(f));
    cout << Solve(1, 0) << "\n";
    // Print();
    return 0;
}
