#include <bits/stdc++.h>

using namespace std;

const int N = 502;

int n, a[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i][i];
    for (int i = 1; i < n; ++i) {
        int piv;
        for (piv = 1; piv <= n - i + 1; ++piv)
            if (a[piv + i - 1][piv] == i) break;
        for (int j = 1; j < piv; ++j)
            a[j + i][j] = a[j + i - 1][j];
        for (int j = piv + 1; j <= n - i + 1; ++j)
            a[j + i - 1][j - 1] = a[j + i - 1][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}