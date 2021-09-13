#include <bits/stdc++.h>

using namespace std;

int test;

bool isVowel(char c) {
    return c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O';
}

int main() {
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        string s;
        cin >> s;
        int ans = INT_MAX;
        for (char c = 'A'; c <= 'Z'; ++c) {
            int cur = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == c) continue;
                if (isVowel(s[i]) ^ isVowel(c)) ++cur;
                else cur += 2;
            }
            ans = min(ans, cur);
        }
        cout << "Case #" << itest << ": " << ans;
        if (itest < test) cout << endl;
    }
    return 0;
}