#include <bits/stdc++.h>

using namespace std;

int q;
string s, t;

int main() {
    cin >> q;
    while (q--) {
        cin >> s >> t;
        string ans = "no";
        for (int i = 0; i < s.size(); ++i)
            for (int j = 0; j < t.size(); ++j)
                if (s[i] == t[j]) ans = "yes";
        cout << ans << "\n";
    }
    return 0;
}
