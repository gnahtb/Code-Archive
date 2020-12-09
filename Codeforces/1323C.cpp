#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

int n, sum[N];
string s;

int main() {
    cin >> n >> s;
    int tmp = 0;
    for (int i = 0; i < n; ++i) tmp += s[i] == '(' ? 1 : -1;
    if (n % 2 != 0 || tmp != 0) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    }
    int ans = 0;
    for (int l = 1, r = 1; l <= n; l = ++r) {
        int curmin = sum[l] - sum[l - 1];
        while (r <= n && sum[r] != sum[l - 1]) {
            ++r;
            curmin = min(curmin, sum[r] - sum[l - 1]);
        }
        if (curmin < 0) {
            ans += r - l + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
