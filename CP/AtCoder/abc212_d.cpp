#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int q;
ll delta = 0;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            pq.push(x - delta);
        } else if (t == 2) {
            ll x;
            cin >> x;
            delta += x;
        } else {
            ll ans = pq.top() + delta;
            pq.pop();
            cout << ans << endl;
        }
    }
}