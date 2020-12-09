#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int xa, ya, xb, yb, xc, yc;
vector<ii> ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int ax[3] = {xa, xb, xc};
    int ay[3] = {ya, yb, yc};
    sort(ax, ax + 3);
    sort(ay, ay + 3);
    int medx = ax[1], medy = ay[1];
    for (int i = min(medx, xa); i <= max(medx, xa); ++i)
        ans.push_back({i, medy});
    for (int i = min(medy, ya); i <= max(medy, ya); ++i)
        ans.push_back({xa, i});
    for (int i = min(medx, xb); i <= max(medx, xb); ++i)
        ans.push_back({i, medy});
    for (int i = min(medy, yb); i <= max(medy, yb); ++i)
        ans.push_back({xb, i});
    for (int i = min(medx, xc); i <= max(medx, xc); ++i)
        ans.push_back({i, medy});
    for (int i = min(medy, yc); i <= max(medy, yc); ++i)
        ans.push_back({xc, i});
    sort(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
    cout << ans.size() << "\n";
    for (ii i : ans) cout << i.first << " " << i.second << "\n";
    return 0;
}
