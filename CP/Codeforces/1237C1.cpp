#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))

using namespace std;
using ll = long long;

struct Point { ll x, y, z; };

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y >> p.z;
    return in;
}

ll sd(Point& p, Point& q) {
    return sqr(p.x - q.x) + sqr(p.y - q.y) + sqr(p.z - q.z);
}

const int N = 50002;

int n;
Point a[N];
bool chk[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        if (chk[i]) continue;
        int pv = -1;
        ll tp = LLONG_MAX;
        for (int j = i + 1; j <= n; ++j) if (!chk[j]) {
            ll tt = sd(a[i], a[j]);
            if (tt < tp) {
                pv = j;
                tp = tt;
            }
        }
        chk[i] = chk[pv] = true;
        cout << i << " " << pv << "\n";
    }
    return 0;
}
