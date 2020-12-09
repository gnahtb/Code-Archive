#include <bits/stdc++.h>

#define sqr(a) ((a) * (a))

using namespace std;
using ll = long long;

struct Point { ll x, y, z; };

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y >> p.z;
    return in;
}

bool operator<(const Point& l, const Point& r) {
    if (l.x == r.x) {
        if (l.y == r.y) return l.z < r.z;
        return l.y < r.y;
    }
    return l.x < r.x;
}

const int N = 1e5 + 2;

int n;
pair<Point, int> a[N];

ll sd(Point& p, Point& q) {
    return sqr(p.x - q.x) + sqr(p.y - q.y) + sqr(p.z - q.z);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    int pre = 0;
    for (int l = 1, r = 1; r <= n; l = r) {
        while (r <= n && a[l].first.x == a[r].first.x) ++r;
        if (pre > 0) {
            int pv = -1;
            ll tp = LLONG_MAX;
            for (int k = l; k < r; ++k) {
                ll tt = sd(a[pre].first, a[k].first);
                if (tp > tt) {
                    pv = k;
                    tp = tt;
                }
            }
            cout << a[pre].second << " " << a[pv].second << "\n";
            pre = 0;
            while (pv > l) {
                swap(a[pv], a[pv - 1]);
                --pv;
            }
            ++l;
        }
        int l1, r1, pre1 = 0;
        for (l1 = l, r1 = l; r1 < r; l1 = r1) {
            while (r1 < r && a[l1].first.y == a[r1].first.y) ++r1;
            if (pre1 > 0) {
                int pv = -1;
                ll tp = LLONG_MAX;
                for (int k = l1; k < r1; ++k) {
                    ll tt = sd(a[pre1].first, a[k].first);
                    if (tp > tt) {
                        pv = k;
                        tp = tt;
                    }
                }
                cout << a[pre1].second << " " << a[pv].second << "\n";
                pre1 = 0;
                while (pv > l1) {
                    swap(a[pv], a[pv - 1]);
                    --pv;
                }
                ++l1;
            }
            int k = l1;
            while (k < r1 && k + 1 < r1) {
                cout << a[k].second << " " << a[k + 1].second << "\n";
                k += 2;
            }
            if (k < r1) pre1 = k;
        }
        pre = pre1;
    }
    return 0;
}
