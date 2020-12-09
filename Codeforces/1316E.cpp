#include <bits/stdc++.h>

#define odd(a) ((a) & 1)

using namespace std;
using ll = long long;

const int N = 1e5 + 2, P = 10;

int n, p, k;
struct Person {
    ll a, s[P];
} pool[N];
ll f[2][1 << P];

void Opt(ll& x, ll y) {
    if (x < y) x = y;
}

inline bool Bit(int b, int i) {
    return b >> i & 1;
}

void Print() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 1 << p; ++j) {
            printf("f[%d][%d] = %lld\n", i, j, f[i][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> p >> k;
    for (int i = 1; i <= n; ++i) cin >> pool[i].a;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < p; ++j)
            cin >> pool[i].s[j];
    sort(pool + 1, pool + n + 1, [](Person& lhs, Person& rhs) { return lhs.a > rhs.a; });
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int m = 0; m < 1 << p; ++m) {
            f[odd(i)][m] = f[odd(i - 1)][m];
            if (i - __builtin_popcount(m) - 1 < k && f[odd(i - 1)][m] >= 0) {
                Opt(f[odd(i)][m], f[odd(i - 1)][m] + pool[i].a);
            }
            for (int j = 0; j < p; ++j)
                if (Bit(m, j) && f[odd(i - 1)][m ^ (1 << j)] >= 0) {
                    Opt(f[odd(i)][m], f[odd(i - 1)][m ^ (1 << j)] + pool[i].s[j]);
                }
        }
    }
    // Print();
    cout << f[odd(n)][(1 << p) - 1] << "\n";
    return 0;
}
