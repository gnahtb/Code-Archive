#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5 + 2;

int n;
ll h[N][2], f[N][2];

int main() {
    cin >> n;
    for (int j = 0; j < 2; ++j)
        for (int i = 1; i <= n; ++i) cin >> h[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            f[i][j] = f[i - 1][j];
            f[i][j] = max(f[i][j], h[i][j] + f[i - 1][j ^ 1]);
        }
    }
    cout << max(f[n][0], f[n][1]) << '\n';
    return 0;
}
