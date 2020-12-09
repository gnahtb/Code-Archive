#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, a[N], b[N], sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i] / 2;
        sum += b[i];
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] % 2 != 0) {
            if (sum > 0 && a[i] < 0) {
                --b[i];
                --sum;
            }
            if (sum < 0 && a[i] > 0) {
                ++b[i];
                ++sum;
            }
        }
    for (int i = 1; i <= n; ++i) cout << b[i] << " ";
    return 0;
}
