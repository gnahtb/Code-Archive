#include <bits/stdc++.h>

using namespace std;

int test, n, l[102];

int main() {
    cin >> test;
    for (int itest = 0; itest < test; ++itest) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> l[i];
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            int cur = n + 1;
            int curp = n + 1;
            for (int j = i; j < n; ++j)
                if (cur > l[j]) cur = l[j], curp = j;
            ans += curp - i + 1;
            int j1 = i, j2 = curp;
            while (j1 < j2) swap(l[j1], l[j2]), ++j1, --j2;
        }
        cout << "Case #" <<  (itest + 1) << ": " << ans << "\n";
    }
    return 0;
}