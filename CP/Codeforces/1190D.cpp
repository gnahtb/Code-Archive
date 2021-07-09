#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using pii = pair<int, int>;

const int N = 2e5 + 2;

int n;
long long ans;
vector<pii> p;
vector<int> lx, ly, a[N];
bool chk[N], chk1[N];

int fen[N];

void inc(int i) {
    for (; i <= sz(lx); i += i & -i) ++fen[i];
}

int get(int i) {
    int sum = 0;
    for (; i; i -= i & -i) sum += fen[i];
    return sum;
}

int get_id(int x, vector<int>& v) {
    return (lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0, x, y; i < n; ++i) {
        cin >> x >> y;
        lx.push_back(x);
        ly.push_back(y);
        p.emplace_back(x, y);
    }
    sort(lx.begin(), lx.end());
    lx.erase(unique(lx.begin(), lx.end()), lx.end());
    sort(ly.begin(), ly.end());
    ly.erase(unique(ly.begin(), ly.end()), ly.end());
    for (pii i : p)
        a[get_id(i.second, ly)].push_back(get_id(i.first, lx));
    for (int i = sz(ly); i ; --i) {
        sort(a[i].begin(), a[i].end());
        for (int j : a[i]) {
            if (chk[j]) continue;
            chk[j] = true;
            inc(j);
        }
//        for (int j = 1; j <= sz(lx); ++j) {
//            if (!chk[j]) continue;
//            int cnt = 0;
//            for (int k = j; k <= sz(lx); ++k) {
//                if (chk1[k]) ++cnt;
//                if (cnt > 0 && chk[k]) ++ans;
//            }
//        }
//        for (int j : a[i]) chk1[j] = false;
        int pre = 0;
        for (int j : a[i]) {
            int t1 = get(j), t2 = get(sz(lx)), t3 = get(j - 1), t4 = get(pre);
            ans += 1LL * (t1 - t4) * (t2 - t3);
            pre = j;
        }
    }
    cout << ans << "\n";
    return 0;
}
