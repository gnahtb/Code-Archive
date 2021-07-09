#include <bits/stdc++.h>

using namespace std;

int n, k, p[105];

int main() {
    freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> k;
        int l = 1, r = n, i = 0, j = 0;
        while (i < k && l < r) {
            if (i == 0) {
                if (l + 1 >= r) {
                    break;
                }
                p[j++] = l++;
                p[j++] = r--;
                p[j++] = l++;
            } else {
                p[j++] = r--;
                p[j++] = l++;
            }
            ++i;
        }
        if (i < k) {
            cout << "-1\n";
        } else {
            for (int i = l; i <= r; ++i) p[j + i - l] = i;
            for (int i = 0; i < n; ++i) cout << p[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}