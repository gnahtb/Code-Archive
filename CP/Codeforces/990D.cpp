#include <bits/stdc++.h>

using namespace std;

#define FOR(i, L, R) for (int i = L; i <= R; ++i)

const int maxN = 1005;

int n, a, b;
bool e[maxN][maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    if (n == 1) { cout << "YES\n0"; return 0; }
    if (a > 1 && b > 1) { cout << "NO\n"; return 0; }
    if (a < 2 && b < 2 && n < 4) { cout << "NO\n"; return 0; }
    cout << "YES\n";
    memset(e, false, sizeof e);
    FOR(i, 1, n - max(a, b)) e[i][i + 1] = e[i + 1][i] = true;
    if (a == 1) FOR(i, 1, n - 1) FOR(j, i + 1, n) e[i][j] ^= 1, e[j][i] ^= 1;
    FOR(i, 1, n)
    {
        FOR(j, 1, n) cout << e[i][j];
        cout << "\n";
    }
    return 0;
}
