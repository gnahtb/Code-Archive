#include <bits/stdc++.h>

using namespace std;

int test;

int main() {
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        if (s[0] == s[s.size() - 1]) { 
            cout << s << endl;
        } else {
            s[0] = s[s.size() - 1];
            cout << s << endl;
        }
    }
    return 0;
}