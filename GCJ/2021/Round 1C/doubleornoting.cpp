#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int LIM = 1 << 17;

int test, s, e, dis[LIM + 2];
string sts, ste;
queue<int> q;

int get_not(int u) {
    if (u == 0) return 1;
    int i = 0, ret = 0;
    while (u > 0) {
        if (u % 2 == 0) ret += 1 << i;
        ++i;
        u /= 2;
    }
    return ret;
}

int main() {
    // freopen("inp.txt", "r", stdin);
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        cin >> sts >> ste;
        reverse(sts.begin(), sts.end());
        reverse(ste.begin(), ste.end());
        s = e = 0;
        for (int i = 0; i < sz(sts); ++i) s += (sts[i] == '1') << i;
        for (int i = 0; i < sz(ste); ++i) e += (ste[i] == '1') << i;
        memset(dis, -1, sizeof(dis));
        while (!q.empty()) q.pop();
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            if (u == e) break;
            q.pop();
            int v1 = get_not(u);
            if (dis[v1] < 0) {
                dis[v1] = dis[u] + 1;
                q.push(v1);
            }
            if ((u << 1) < LIM && dis[u << 1] < 0) {
                dis[u << 1] = dis[u] + 1;
                q.push(u << 1);
            }
        }
        cout << "Case #" << itest << ": ";
        if (dis[e] < 0)
            cout << "IMPOSSIBLE\n";
        else
            cout << dis[e] << "\n";
    }
    return 0;
}