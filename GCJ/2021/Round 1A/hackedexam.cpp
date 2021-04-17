#include <bits/stdc++.h>

using namespace std;

const int N = 3, Q = 40;

int test, n, q, sa[N], ss[N], tot = 0, b1[Q];

int get_bit(int m, int i) {
    return m >> i & 1;
}

int main() {
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        tot = 0;
        cin >> n >> q;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int ca = 0;
            for (int j = 0; j < q; ++j) ca += (s[j] == 'T') << j;
            sa[i] = ca;
            cin >> ss[i];
        }
        memset(b1, 0, sizeof(b1));
        for (int m = 0; m < 1 << q; ++m) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                int cs = 0;
                for (int j = 0; j < q; ++j) {
                    if (get_bit(m, j) == get_bit(sa[i], j)) {
                        ++cs;
                    }
                }
                if (cs == ss[i]) ++cnt;
            }
            if (cnt == n) {
                ++tot;
                for (int j = 0; j < q; ++j)
                    if (get_bit(m, j)) ++b1[j];
            }
        }
        cout << "Case #" << itest << ": ";
        int tot_denom = 0;
        for (int i = 0; i < q; ++i) {
            if (b1[i] > tot - b1[i]) {
                cout << "T";
                tot_denom += b1[i];
            } else {
                cout << "F";
                tot_denom += tot - b1[i];
            }
        }
        int g = __gcd(tot_denom, tot);
        cout << " " << (tot_denom / g) << "/" << (tot / g) << "\n";
    }
    return 0;
}