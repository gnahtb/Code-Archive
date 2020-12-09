#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

const ll Mod = 1e9 + 7;

string s;
ll ans = 1, f[100002];

int main() {
    cin >> s;
    // int cnt = 0;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= sz(s); ++i)
        f[i] = (f[i - 1] + f[i - 2]) % Mod;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == 'w' || s[i] == 'm') ans = 0;
        if (s[i] != 'n' && s[i] != 'u') continue;
        int j = i;
        while (j < sz(s) && s[i] == s[j]) ++j;
        (ans *= f[j - i]) %= Mod;
        i = j - 1;
    }
    cout << ans << "\n";
    return 0;
}
