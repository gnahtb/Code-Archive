#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 55;

int n, a[N_MAX], f[N_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int s = 0;
    for (int i = n; i; --i) {
        s += a[i];
        f[i] = max(f[i + 1], s - f[i + 1]);
    }
    printf("%d %d\n", s - f[1], f[1]);
    return 0;
}
