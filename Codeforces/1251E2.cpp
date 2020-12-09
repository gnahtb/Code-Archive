#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 2e5 + 2;

int test;
int n;
int pref[N];
vector<int> voters[N];
priority_queue<int, vector<int>, greater<int>> pq;

void Reset() {
    while (!pq.empty()) pq.pop();
    for (int i = 0; i <= n; ++i) voters[i].clear();
    fill(pref, pref + n + 1, 0);
}

int main() {
    scanf("%d", &test);
    while (test--) {
        Reset();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int m, p;
            scanf("%d%d", &m, &p);
            voters[m].push_back(p);
        }
        for (int i = 0; i <= n; ++i) {
            if (i > 0) pref[i] = pref[i - 1] + sz(voters[i - 1]);
            sort(voters[i].begin(), voters[i].end());
        }
        int cnt = 0;
        long long ans = 0;
        for (int i = n; i >= 0; --i) {
            if (voters[i].size() == 0) continue;
            for (int j = 0; j < sz(voters[i]); ++j)
                pq.push(voters[i][j]);
            int tmp = max(0, i - pref[i] - cnt);
            for (int j = 0; j < tmp; ++j) {
                ans += pq.top();
                pq.pop();
                ++cnt;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
