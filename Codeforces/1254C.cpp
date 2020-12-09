#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<ll> area;
vector<int> side;
vector<int> up, down;
vector<int> ans;

ll Query(int t, int i, int j, int k) {
    cout << t << " " << i << " " << j << " " << k << "\n";
    cout.flush();
    ll ret;
    cin >> ret;
    return ret;
}

void Solve(vector<int>& v) {
    ll amax = 0;
    int imax = 0;
    for (int i : v) {
        area[i] = Query(1, 1, 2, i);
        if (area[i] > amax) {
            amax = area[i];
            imax = i;
        }
    }
    for (int i : v) {
        side[i] = i == imax ? 0 : Query(2, 1, imax, i);
    }
    sort(v.begin(), v.end(), [&](int x, int y) {
        if (side[x] == side[y]) {
            if (side[x] > 0) return area[x] < area[y];
            else return area[x] > area[y];
        }
        return side[x] > side[y];
    });
    for (int i : v) ans.push_back(i);
}

int main() {
    cin >> n;
    area.assign(n + 2, 0);
    side.assign(n + 2, 0);
    for (int i = 3; i <= n; ++i) {
        if (Query(2, 1, 2, i) > 0) {
            up.push_back(i);
        } else {
            down.push_back(i);
        }
    }
    ans.push_back(1);
    Solve(up);
    ans.push_back(2);
    Solve(down);
    cout << "0 ";
    reverse(ans.begin(), ans.end());
    rotate(ans.begin(), ans.begin() + (n - 1), ans.end());
    for (int i : ans) cout << i << " ";
    cout << "\n";
    cout.flush();
    return 0;
}
