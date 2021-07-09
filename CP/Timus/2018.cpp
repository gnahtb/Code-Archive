#include <bits/stdc++.h>

#define odd(a) ((a) & 1)

using namespace std;

const int MOD = 1e9 + 7;
const int AB = 302;

int n, a, b;

// 0 for a
// 1 for b
int f[2][AB][2];

void Add(int& x, int y) {
    (x += y) %= MOD;
}

int main() {
    cin >> n >> a >> b;
    memset(f, 0, sizeof(f));
    f[1][1][0] = f[1][1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        memset(f[odd(i)], 0, sizeof(f[odd(i)]));
        for (int j = 1; j <= a; ++j) {
            Add(f[odd(i)][j][0], f[odd(i - 1)][j - 1][0]);
            Add(f[odd(i)][1][1], f[odd(i - 1)][j][0]);
        }
        for (int j = 1; j <= b; ++j) {
            Add(f[odd(i)][j][1], f[odd(i - 1)][j - 1][1]);
            Add(f[odd(i)][1][0], f[odd(i - 1)][j][1]);
        }
    }
    int ans = 0;
    for (int j = 1; j <= a; ++j) Add(ans, f[odd(n)][j][0]);
    for (int j = 1; j <= b; ++j) Add(ans, f[odd(n)][j][1]);
    cout << ans << "\n";
    return 0;
}