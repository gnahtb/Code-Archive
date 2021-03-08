#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

const int LIM = 2e5;
const int N = 2e5 + 2;
const ll MOD = 1e9 + 7;

ll power(ll x, ll y) {
    if (y == 0) return 1;
    ll z = power(x, y / 2);
    (z *= z) %= MOD;
    if (y % 2 != 0) (z *= x) %= MOD;
    return z;
}

int n, q, p[LIM + 2];
ll curans = 1;
multiset<int> pw[LIM + 2];
map<int, int> a[N];

vector<pair<int, int>> fact(int x) {
    vector<pair<int, int>> ans;
    ans.clear();
    while (x > 1) {
        int y = p[x], z = 0;
        while (x % y == 0) x /= y, ++z;
        ans.emplace_back(y, z);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 2; i <= LIM; ++i) p[i] = i;
    for (int i = 2; i * i <= LIM; ++i) if (p[i] == i)
        for (int j = i * i; j <= LIM; j += i) p[j] = i;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int atmp;
        cin >> atmp;
        vector<pair<int, int>> v = fact(atmp);
        for (pair<int, int> j : v) {
            a[i][j.first] = j.second;
            pw[j.first].insert(j.second);
        }
    }
    for (int i = 2; i <= LIM; ++i)
        if (sz(pw[i]) == n) (curans *= power(i, *pw[i].begin())) %= MOD;
    while (q--) {
        int i, x;
        cin >> i >> x;
        vector<pair<int, int>> v = fact(x);
        for (pair<int, int> j : v) {
            map<int, int>::iterator it = a[i].find(j.first);
            if (it == a[i].end()) {
                a[i][j.first] = j.second;
                pw[j.first].insert(j.second);
                if (sz(pw[j.first]) == n) {
                    (curans *= power(j.first, *pw[j.first].begin())) %= MOD;
                }
            } else {
                int pw_prev = sz(pw[j.first]) == n ? *pw[j.first].begin() : 0;
                pw[j.first].erase(pw[j.first].find(it->second));
                it->second += j.second;
                pw[j.first].insert(it->second);
                int pw_cur = *pw[j.first].begin();
                if (sz(pw[j.first]) == n)
                    (curans *= power(j.first, pw_cur - pw_prev)) %= MOD;
            }
        }
        cout << curans << "\n";
    }
    return 0;
}