#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, fen[N], ans = 0;

inline void upd(int i, int v) {
    for (; i <= n; i += i & -i) fen[i] = max(fen[i], v);
}

inline int get(int i) {
    int ret = 0;
    for (; i; i -= i & -i) ret = max(ret, fen[i]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        int t = get(a) + 1;
        ans = max(ans, t);
        upd(a, t);
    }
    cout << ans << "\n";
    return 0;
}
