#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define fi first
#define se second
#define odd(a) ((a) & 1)
#define sz(a) int(a.size())

typedef pair<int, int> ii;

const int maxN = 1E5 + 5;

int n;
set<ii, greater<ii>> p; //max
set<ii> q; //min
vector<ii> ans;

void enter() {
    int t, x = 0;
    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t, ++m[t];
    for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
        if (odd(i -> se)) p.insert({i -> fi, x}), q.insert({i -> fi, x++});
}

void solve() {
    for (int i = 0; i < n; ++i) {
        if (p.empty()) break;
        ii u = *(p.begin()), v = *(q.begin());
        p.erase(p.begin()); q.erase(q.begin());
        set<ii>::iterator x = p.find(v), y = q.find(u);
        if (x != p.end() && y != q.end())
            p.erase(x), q.erase(y);
        if (u.se == v.se) {
            if (odd(u.fi)) { cout << "-1\n"; return; }
            ans.push_back({u.fi, u.fi / 2});
        } else {
            if (u.fi == v.fi) continue;
            int t = u.fi - v.fi;
            ans.push_back({u.fi, v.fi});
            p.insert({t, u.se}); q.insert({t, u.se});
        }
    }
    if (!p.empty()) { cout << "-1\n"; return; }
    cout << sz(ans) << "\n";
    for (ii i: ans) cout << i.fi << " " << i.se << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    enter();
    solve();
}