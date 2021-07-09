#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> TPair;

const int maxN = 70005;

int n;
string ans[maxN];
vector<TPair> a;

void process(string s, int id) {
    for (int i = 0; i < 9; ++i) {
        string tmp = "";
        for (int j = i; j < 9; ++j) {
            tmp += s[j];
            TPair p;
            p.first = tmp;
            p.second = id;
            a.push_back(p);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) ans[i] = "9999999999";
    int i = 0;
    while (i < (int)a.size()) {
        int j = i;
        while (j < (int)a.size()-1 && a[i].first == a[j+1].first) ++j;
        bool flag = true;
        for (int k = i+1; k <= j; ++k)
            if (a[k].second != a[k-1].second) {
                flag = false;
                break;
            }
        if (flag && ans[a[i].second].length() > (a[i].first).length())
            ans[a[i].second] = a[i].first;
        i = j+1;
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        process(s, i);
    }
    sort(a.begin(), a.end());
    solve();
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
