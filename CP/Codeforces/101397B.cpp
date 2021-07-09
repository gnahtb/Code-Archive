#include <bits/stdc++.h>
 
using namespace std;
 
#define long long long
#define odd(a) ((a) & 1)
#define sqr(a) (a) * (a)
#define sz(a) (int)a.size()
#define fi first
#define se second
 
typedef pair<int, int> ii;
 
void factorize(int x, vector<ii> &v) {
    while (x > 1) {
        int d = x, pw = 0;
        for (int i = 2; sqr(i) <= x; ++i) if (!(x % i)) { d = i; break; }
        while (!(x % d)) x /= d, ++pw;
        v.push_back({d, pw});
    }
}
 
inline int getbit(int s, int i) {
    return s >> i & 1;
}
 
int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int a, b;
        long ansa, ansb, sum = LLONG_MAX;
        vector<ii> fa, fb;
        vector<int> prm;
        cin >> a >> b;
        factorize(a, fa);
        factorize(b, fb);
        for (ii i : fb) {
            bool flag = false;
            for (ii &j : fa) if (i.fi == j.fi) {
                flag = true;
                j.se += i.se;
                break;
            }
            if (!flag) fa.push_back(i);
        }
        for (ii i : fa) if (odd(i.se)) prm.push_back(i.fi);
        for (int m = 0; m < 1 << sz(prm); ++m) {
            long p[2] = {1, 1};
            for (int i = 0; i < sz(prm); ++i) p[getbit(m, i)] *= (long)prm[i];
            if (p[0] + p[1] < sum) {
                ansa = p[0];
                ansb = p[1];
                sum = ansa + ansb;
            }
        }
        cout << ansa << " " << ansb << "\n";
    }
    return 0;
}