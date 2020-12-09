#include <bits/stdc++.h>

using namespace std;

int k;
int n, cnt[30];
string s, t;
vector<pair<int, int>> ans;

void Solve() {
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) continue;
        int p = -1;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == s[i]) {
                p = j;
                break;
            }
        }
        if (p < 0) {
            int q = -1;
            for (int j = i + 1; j < n; ++j)
                if (t[j] == s[i]) {
                    q = j;
                    break;
                }
            if (q < 0) {
                cout << "No\n";
                return;
            }
            ans.emplace_back(i + 1, q);
            swap(s[i + 1], t[q]);
            p = i + 1;
        }
        ans.emplace_back(p, i);
        swap(t[i], s[p]);
    }
    cout << "Yes\n" << ans.size() << "\n";
    for (pair<int, int> i : ans)
        cout << (i.first + 1) << " " << (i.second + 1) << "\n";
}

int main() {
    cin >> k;
    while (k--) {
        ans.clear();
        cin >> n >> s >> t;
        Solve();
    }
    return 0;
}
