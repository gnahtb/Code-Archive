#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                if (s[i] == 'a') s[i] = 'b';
                else s[i] = 'a';
            } else {
                if (s[i] == 'z') s[i] = 'y';
                else s[i] = 'z';
            }
        }
        cout << s << "\n";
    }
    return 0;
}