#include <bits/stdc++.h>

using namespace std;

const int Lim = 102;
const char chr[62] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9'
};

int t, r, c, k;
char a[Lim][Lim], ans[Lim][Lim];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> r >> c >> k;
        int rice = 0;
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j) {
                cin >> a[i][j];
                rice += a[i][j] == 'R';
            }
        int tmp = rice % k, tmp1 = rice / k, cnt = 0;
        for (int i = 1; i <= r; ++i) {
            int l = 1, rg = c + 1, d = 1;
            if (i % 2 == 0) {
                l = c;
                rg = 0;
                d = -1;
            }
            for (int j = l; j != rg; j += d) {
                ans[i][j] = chr[k - 1];
                if (a[i][j] == 'R') ++cnt;
                if (tmp > 0) {
                    if (cnt == tmp1 + 1) {
                        cnt = 0;
                        --k;
                        if (k == 0) k = 1;
                        --tmp;
                    }
                } else {
                    if (cnt == tmp1) {
                        cnt = 0;
                        --k;
                        if (k == 0) k = 1;
                    }
                }
            }
        }
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) cout << ans[i][j];
            cout << "\n";
        }
    }
    return 0;
}
