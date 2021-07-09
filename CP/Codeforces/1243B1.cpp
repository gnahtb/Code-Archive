#include <bits/stdc++.h>

using namespace std;

int k;
int n;
string s, t;
vector<int> v;

int main() {
    cin >> k;
    while (k--) {
        cin >> n >> s >> t;
        v.resize(n + 2);
        int flag = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == t[i]) {
                v[i] = 1;
            } else {
                v[i] = 0;
                ++flag;
            }
        if (flag != 2) {
            cout << "No\n";
            continue;
        }
        int p1, p2;
        for (int i = 0; i < n; ++i)
            if (s[i] != t[i]) {
                p1 = i;
                break;
            }
        for (int i = n - 1; i >= 0; --i)
            if (s[i] != t[i]) {
                p2 = i;
                break;
            }
        if (s[p1] == s[p2] && t[p1] == t[p2]) {
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
    }
    return 0;
}
