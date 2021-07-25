#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7, N = 1e5 + 2;
const string C = "chokudai";

string s;
int f[N][10];

int main() {
    memset(f, 0, sizeof(f));
    cin >> s;
    f[0][0] = 1;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j < 9; ++j) f[i + 1][j] = f[i][j];
        for (int j = 1; j < 9; ++j)
            if (s[i] == C[j - 1]) {
                (f[i + 1][j] += f[i][j - 1]) %= MOD;
                break;
            }
    }
    cout << f[s.size()][8];
    return 0;
}