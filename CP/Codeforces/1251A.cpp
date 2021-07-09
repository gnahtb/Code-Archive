#include <bits/stdc++.h>

using namespace std;

int t;
string s;
bool ans[30];

int main() {
    cin >> t;
    while (t--) {
        memset(ans, false, sizeof ans);
        cin >> s;
        for (int l = 0, r = 0; l < s.size(); l = r) {
            while (r < s.size() && s[l] == s[r]) ++r;
            int d = r - l;
            if (d % 2 != 0) ans[s[l] - 'a'] = true;
        }
        for (int i = 0; i < 26; ++i)
            if (ans[i]) cout << char('a' + i);
        cout << "\n";
    }
    return 0;
}
