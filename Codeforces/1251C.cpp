#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 3e5 + 2;
struct FenTree {
    int n, fen[N];

    void reset(int _n) {
        n = _n;
        fill(fen + 1, fen + n + 1, 0);
    }

    void inc(int i) {
        for (; i <= n; i += i & -i) ++fen[i];
    }

    int sum(int i) {
        int ret = 0;
        for (; i; i -= i & -i) ret += fen[i];
        return ret;
    }
} fw[10], par;

int t;
string a, ans;
vector<int> v[2];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> a;
        for (int i = 0; i < sz(a); ++i) {
            v[(a[i] - '0') % 2 == 0].push_back(i);
        }
        reverse(v[0].begin(), v[0].end());
        reverse(v[1].begin(), v[1].end());
        ans = "";
        for (int i = 0; i < sz(a); ++i) {
            if (v[1].empty() || (!v[0].empty() && a[v[0].back()] < a[v[1].back()])) {
                ans += a[v[0].back()];
                v[0].pop_back();
            } else {
                ans += a[v[1].back()];
                v[1].pop_back();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
