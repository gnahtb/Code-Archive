#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        bool flag = false;
        for (int mask = 0; mask < 8; ++mask) {
            string brac = "(((";
            if (mask & 1) brac[0] = ')';
            if (mask >> 1 & 1) brac[1] = ')';
            if (mask >> 2 & 1) brac[2] = ')';
            int cur = 0;
            bool flag1 = true;
            for (int i = 0; i < s.size(); ++i)
                if (brac[s[i] - 'A'] == '(') {
                    ++cur;
                } else {
                    --cur;
                    if (cur < 0) {
                        flag1 = false;
                        break;
                    }
                }
            if (cur != 0) flag1 = false;
            flag |= flag1;
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}