#include <bits/stdc++.h>

using namespace std;

const int n_max = 1005;

int n;
pair<int, int> xy[n_max], ab[n_max];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> xy[i].first >> xy[i].second;
    for (int i = 1; i <= n; ++i) cin >> ab[i].first >> ab[i].second;
    sort(xy + 1, xy + n + 1);
    sort(ab + 1, ab + n + 1, greater<pair<int, int>>());
    cout << xy[1].first + ab[1].first << " " << xy[1].second + ab[1].second << "\n";
    return 0;
}
