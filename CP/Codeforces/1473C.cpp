#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        int tmp = n - k + 1;
        vector<int> ans;
        ans.clear();
        for (int i = 1; i <= k; ++i) ans.push_back(i);
        reverse(ans.end() - tmp, ans.end());
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}