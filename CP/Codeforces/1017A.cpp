#include <bits/stdc++.h>

using namespace std;

int n, s[1005], id[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        id[i] = i;
        cin >> a >> b >> c >> d;
        s[i] = a + b + c + d;
    }
    sort(id + 1, id + n + 1, [](int x, int y) {
        return s[x] == s[y] ? x < y : s[x] > s[y];
    });
    for (int i = 1; i <= n; ++i) if (id[i] == 1) {
        cout << i << "\n";
        break;
    }
    return 0;
}
