#include <bits/stdc++.h>

using namespace std;

int test, n;
string s;

int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        cin >> n >> s;
        int j = -1;
        for (int i = 0; i < n; ++i)
            if (s[i] != 'F') {
                j = i;
                break;
            }
        cout << "Case #" << itest << ": ";
        if (j < 0) {
            cout << "0\n";
        } else {
            bool left = s[j] == 'X';
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'O' && left) ++ans, left = false;
                else if (s[i] == 'X' && !left) ++ans, left = true;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}