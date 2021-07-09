#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1E5 + 5;

int n, s[N][2], cnt0 = 0, cnt1 = 0;
ll ans = 0;
char a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        s[i][0] = s[i - 1][0];
        s[i][1] = s[i - 1][1];
        if (b[i] == '0') {
            s[i][0] += (a[i] == '0');
            s[i][1] += (a[i] == '1');
        } else if (a[i] == '0') ++cnt0; else ++cnt1;
    }
    // for (int i = 1; i <= n; ++i) cout << s[i][0] << " " << s[i][1] << "\n";
    for (int i = 1; i <= n; ++i) if (b[i] == '0') {
        if (a[i] == '0') ans += (ll)cnt1 + s[i][1];
        else ans += (ll)cnt0 + s[i][0];
    }
    cout << ans << "\n";
    return 0;
}
