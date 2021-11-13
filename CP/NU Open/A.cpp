#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LOOKUP[10] = {0,1,3,2,2,3,1,0,0,1};

ll C[30][30];

ll sum_digit(ll n) {
    ll ret = 0;
    while (n > 0) ret += n % 10, n /= 10;
    return ret;    
}

ll g(ll n) {
    C[0][0] = 1;
    for (int i = 1; i < 30; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 4;
    }
    string s = to_string(n);
    ll ret = 0;
    int cur = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '0') continue;
        ll rets = 0;
        for (int j = 1; j < (int)s.size() - i; ++j) {
            (rets += (j + cur) * C[s.size() - i - 1][j] % 4) %= 4;
        }
        (ret += (s[i] - '0') * rets % 4) %= 4;
        if (s[i] == '9') ++cur;
    }
    return ret % 4;
}

ll f(ll n) {
    if (n < 10) return LOOKUP[n];
    ll q = n / 10;
    ll r = n % 10;
    return (q + 2 * f(q - 1) + r * (r+1) / 2 + (r + 1) * sum_digit(q)) % 4;
}

ll h(ll n) {
    if (n < 9) return (n + 1) * n / 2 % 4;
    ll pw = 1;
    while (pw * 9 <= n) pw *= 9;
    ll a = n / pw;
    ll b = n % pw;
    // cerr << n << " " << pw << " " << a << " " << b << endl;
    return (a * (a - 1) / 2 * pw % 4 + a * (b + 1) % 4 + h(b) % 4) % 4;
}

ll n;

int main() {
    cin >> n;
    cout << h(n);
    // ll a = f(n);
    // ll b = g(n);
    // cout << a << " " << b << endl;
    // ll ans = (f(n) - g(n) + 4) %  4;
    // cout << ans << endl;
    return 0;
}