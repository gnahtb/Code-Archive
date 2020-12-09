#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i)
        if (s[i] > s[i + 1]) {
            s.erase(i, 1);
            cout << s << "\n";
            return 0;
        }
    s.erase(n - 1, 1);
    cout << s << "\n";
    return 0;
}
