#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

typedef pair<int, int> ii;

const int N_MAX = 505;

int n, d[N_MAX], deg[N_MAX];
vector<int> a[2];
vector<ii> edges;

int main() {
    ios_base::sync_with_stdio(false);
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        if (d[i] == 1) a[0].push_back(i);
        else a[1].push_back(i), sum += d[i];
    }
    if (sz(a[1]) == 0) {
        if (sz(a[0]) > 2) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES 1\n1\n1 2";
    } else {
        int tmp = sz(a[1]) - 1, tmp1 = sz(a[1]) == 1 ? d[a[1][0]] : sum - (sz(a[1]) - 1) * 2;
        if (tmp1 < sz(a[0])) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES ";
        for (int i = 0; i < sz(a[1]) - 1; ++i)
            edges.push_back({a[1][i], a[1][i + 1]});
        if (sz(a[0]) == 1) {
            ++tmp;
            edges.push_back({a[0][0], a[1][0]});
        } else if (sz(a[0]) > 1) {
            for (int i = 0; i < sz(a[1]); ++i) {
                deg[a[1][i]] = d[a[1][i]] - 2;
                if (i == 0 || i == sz(a[1]) - 1) ++deg[a[1][i]];
            }
            if (sz(a[1]) == 1) ++deg[a[1][0]];
            tmp += 2;
            edges.push_back({a[0][0], a[1][0]}); --deg[a[1][0]];
            edges.push_back({a[0][1], a[1].back()}); --deg[a[1].back()];
            for (int i = 2, x = 0; i < sz(a[0]); ++i) {
                while (deg[a[1][x]] == 0) ++x;
                edges.push_back({a[0][i], a[1][x]}); --deg[a[1][x]];
            }
        }
        cout << tmp << "\n" << sz(edges) << "\n";
        for (ii i : edges) cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
