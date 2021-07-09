#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 105;

int n, a[N_MAX << 1], ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    n <<= 1;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; i += 2) {
        int j = i + 1;
        for (; j <= n; ++j) if (a[i] == a[j]) break;
        while (j > i + 1)
            swap(a[j], a[j - 1]), ++ans, --j;
    }
    cout << ans << "\n";
    return 0;
}
