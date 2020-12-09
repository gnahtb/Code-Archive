#include <bits/stdc++.h>

using namespace std;

const int MAXCHAR = 24;

int n, f[1 << MAXCHAR], ans = 0;

inline int getBit(int m, int i) { return m >> i & 1; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        set<int> st;
        cin >> s;
        for (int m = 1; m < 8; ++m) {
            int x = 0;
            for (int j = 0; j < 3; ++j)
                if (getBit(m, j)) x |= 1 << (s[j] - 'a');
            st.insert(x);
        }
        for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
            f[*it] += (__builtin_popcount(*it) & 1) ? 1 : -1;
    }
    for (int i = 0; i < MAXCHAR; ++i)
        for (int m = 0; m < 1 << MAXCHAR; ++m)
            if (getBit(m ,i)) f[m] += f[m ^ (1 << i)];
    for (int i = 0; i < 1 << MAXCHAR; ++i) ans ^= f[i] * f[i];
    cout << ans << "\n";
    return 0;
}
