#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

int n, m, p, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i) if (a[i] % p != 0) {
        for (int j = 0; j < m; ++j) if (b[j] % p != 0) {
            printf("%d\n", i + j);
            return 0;
        }
    }
    return 0;
}
