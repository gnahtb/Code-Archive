#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
    if (l == r) return l;
    cout << "? " << l << " " << r << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int m = ask(1, n);
    if (m > 1 && ask(1, m) == m) {
        int l1 = 1, r1 = m - 1, ans = -1;
        while (l1 <= r1) {
            int m1 = (l1 + r1) / 2;
            int tmp = ask(m1, m);
            if (tmp == m) {
                ans = m1;
                l1 = m1 + 1;
            } else {
                r1 = m1 - 1;
            }
        }
        cout << "! " << ans << endl;
        return 0;
    }
    if (m < n && ask(m, n) == m) {
        int l1 = m + 1, r1 = n, ans = -1;
        while (l1 <= r1) {
            int m1 = (l1 + r1) / 2;
            int tmp = ask(m, m1);
            if (tmp == m) {
                ans = m1;
                r1 = m1 - 1;
            } else {
                l1 = m1 + 1;
            }
        }
        cout << "! " << ans << endl;
        return 0;
    }
}