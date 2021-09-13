#include <bits/stdc++.h>

using namespace std;

int ask(int i, int j, int k) {
    cout << i << " " << j << " " << k << endl;
    int ans;
    cin >> ans;
    if (ans < 0) exit(0);
    return ans;
}

int main() {
    int test, n, q;
    cin >> test >> n >> q;
    for (int itest = 1; itest <= test; ++itest) {
        int ans[200], l, r;
        int tmp = ask(1, 2, 3);
        ans[99] = (tmp + 1) % 3 + 1;
        ans[100] = tmp;
        ans[101] = tmp % 3 + 1;
        l = 99;
        r = 101;
        for (int i = 4; i <= n; ++i) {
            int lo = l + 1, hi = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                tmp = ask(ans[mid - 1], ans[mid], i);
                if (tmp == i) {
                    for (int j1 = l; j1 < mid; ++j1) ans[j1 - 1] = ans[j1];
                    ans[mid - 1] = i;
                    --l;
                    break;
                } else if (tmp == ans[mid - 1]) {
                    if (mid == l + 1) {
                        ans[--l] = i;
                        break;
                    }
                    hi = mid - 1;
                } else {
                    if (mid == r) {
                        ans[++r] = i;
                        break;
                    }
                    lo = mid + 1;
                }
            }
        }
        for (int i = l; i <= r; ++i) cout << ans[i] << " ";
        cout << endl;
        int ver;
        cin >> ver;
        if (ver < 0) return 0;
    }
    return 0;
}