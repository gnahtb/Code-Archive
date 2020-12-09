#include <bits/stdc++.h>

using namespace std;

string tmp;

int main() {
    cin >> tmp;
    for (int i = 1; i <= 5; ++i) {
        string cur;
        cin >> cur;
        if (cur[0] == tmp[0] || cur[1] == tmp[1]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
