#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 10;
        for (int m = 0; m < 1024; ++m) {
            bool ok = true;
            for (int i = 0; i < 10; ++i)
                if (s[i] == '?') continue;
                else if (s[i] - '0' != ((m >> i) & 1)) {
                    ok = false;
                    break;
                }
            if (!ok) continue;
            // bitset<10> t1 = bitset<10>(m);
            int team[2] = {0, 0};
            for (int i = 0; i < 10; ++i) {
                team[i % 2] += m >> i & 1;
                int maxp = team[i % 2];
                int maxpo = team[(i + 1) % 2];
                for (int j = i + 1; j < 10; ++j)
                    if (j % 2 == i % 2) ++maxp;
                    else ++maxpo;
                if (maxp < team[(i + 1) % 2] || maxpo < team[i % 2]) {
                    ans = min(ans, i + 1);
                    break;
                }
            }
            // cout << bitset<10>(m) << " " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}