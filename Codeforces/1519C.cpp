#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int test, n, u[N];
ll ans[N];
vector<int> stu[N];

int main() {
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 0; i <= n; ++i) {
            stu[i].clear();
            ans[i] = 0;
        }
        for (int i = 1; i <= n; ++i) cin >> u[i];
        for (int i = 1; i <= n; ++i) {
            int s;
            cin >> s;
            stu[u[i]].push_back(s);
        }
        for (int i = 1; i <= n; ++i) {
            sort(stu[i].begin(), stu[i].end());
            vector<long long> ssum;
            ssum.push_back(0);
            ll cursum = 0;
            for (int j : stu[i]) {
                cursum += j;
                ssum.push_back(cursum);
            }
            for (int j = 1; j <= sz(stu[i]); ++j) {
                ans[j] += cursum - ssum[sz(stu[i]) % j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}