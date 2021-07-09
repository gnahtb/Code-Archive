#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll oo = 1e9;

ll query(ll xq, ll yq) {
    cout << "Q " << xq << " " << yq << endl;
    cout.flush();
    ll ret;
    cin >> ret;
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a1 = query(0, oo);
        ll a2 = query(oo, oo);
        ll a3 = query(oo, 0);

        ll d13 = a2 - a3;
        ll d24 = a2 - a1;

        ll xm = (oo - d24) / 2;
        ll ym = (oo - d13) / 2;

        ll x1 = oo - query(xm, oo);
        ll x2 = oo - query(oo, ym);
        ll x3 = query(xm, 0);
        ll x4 = query(0, ym);

        cout << "A " << x4 << " " << x3 << " " << x2 << " " << x1 << endl;
        cout.flush();
        
        int v;
        cin >> v;
        if (v < 0) return 0;
    }

    return 0;
}