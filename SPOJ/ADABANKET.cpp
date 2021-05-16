#include <bits/stdc++.h>

using namespace std;

const int N = 902;

int n, ans = N;
bool a[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            cnt += a[i][j];
        }
        ans = min(ans, cnt);
    }
    cout << (ans * 2) << "\n";
    return 0;
}