#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

string t, s;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    int l = 0, r = sz(t) - 1;
    while (l <= r) {
        if ((r - l + 1) % 2 == 0) s += t[r--];
        else s += t[l++];
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}
