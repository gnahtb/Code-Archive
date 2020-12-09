#include <bits/stdc++.h>

using namespace std;

int n, k, cnt[26];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) ++cnt[s[i] - 'A'];
    int tmp = n;
    for (int i = 0; i < k; ++i) tmp = min(tmp, cnt[i]);
    cout << tmp * k << "\n";
    return 0;
}
