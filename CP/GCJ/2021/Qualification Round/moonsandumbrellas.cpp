#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int oo = 2e9;

int test, x, y, f[1002][2];
string s;

int main() {
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        cin >> x >> y >> s;
        f[0][0] = f[0][1] = 0;
        for (int i = 1; i <= sz(s); ++i) {
            // 0 -> C
            // 1 -> J
            f[i][0] = f[i][1] = oo;
            if (s[i - 1] == '?') {
                if (f[i - 1][0] < oo) {
                    f[i][0] = min(f[i][0], f[i - 1][0]);
                    f[i][1] = min(f[i][1], f[i - 1][0] + x);
                }
                if (f[i - 1][1] < oo) {
                    f[i][0] = min(f[i][0], f[i - 1][1] + y);
                    f[i][1] = min(f[i][1], f[i - 1][1]);
                }
            } else if (s[i - 1] == 'C') {
                f[i][0] = min(f[i - 1][1] + y, f[i - 1][0]);
            } else {
                f[i][1] = min(f[i - 1][0] + x, f[i - 1][1]);
            }
            cout << f[i][0] << " " << f[i][1] << "\n";
        }
        cout << "Case #" << itest << ": " << min(f[sz(s)][0], f[sz(s)][1]) << "\n";
    }
    return 0;
}