#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

int a, b;
string s;
vector<int> bk;

int main() {
    cin >> a >> b >> s;
    for (int i = 0; i < sz(s); ++i)
        if (s[i] == 'B') bk.push_back(i);
    ll ans = LLONG_MAX;
    for (int as = 0; as <= sz(bk); ++as) {
        int j = sz(bk) - 1;
        ll tmp = 0;
        for (int i = 0; i < as; ++i)
            if (s[i] == 'W') {
                tmp += a;
                --j;
            }
        for (int i = 0; i < sz(bk); ++i) {
            if (bk[i] >= as) {
                j = i;
                break;
            }
        }
        for (int i = as; i < sz(bk); ++i) {
            tmp += (a - b) * (bk[j] - i);
            ++j;
        }
        ans = min(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}