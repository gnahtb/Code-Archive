#include <bits/stdc++.h>

using namespace std;

int test, n;
string s;

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end());
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == t[i]) ++ans;
        ans = n - ans;
        cout << ans << endl;
    }
    return 0;
}