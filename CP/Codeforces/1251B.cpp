#include <bits/stdc++.h>

using namespace std;

const int N = 52;

int q;
int n, l[N];

int main() {
    cin >> q;
    while (q--) {
        cin >> n;
        int c0 = 0, c1 = 0;
        for (int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            l[i] = s.size();
            for (int j = 0; j < l[i]; ++j)
                if (s[j] == '0') ++c0;
                else ++c1;
        }
        sort(l + 1, l + n + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (l[i] % 2 == 0) {
                for (int j = 0; j <= l[i]; ++j)
                    if (j % 2 == 0 && c0 >= j && c1 >= l[i] - j) {
                        c0 -= j;
                        c1 -= l[i] - j;
                        ++ans;
                        break;
                    }
            } else ++ans;
        cout << ans << "\n";
    }
}
