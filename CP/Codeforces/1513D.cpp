#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int test, n, p, a[N], lab[N], id[N];

int get_label(int u) {
    return lab[u] < 0 ? u : lab[u] = get_label(lab[u]);
}

void merge_label(int u, int v) {
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
}

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> p;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            id[i] = i;
            lab[i] = -1;
        }
        sort(&(id[1]), &(id[n + 1]), [&](int x, int y) {
            return a[x] < a[y];
        });
        long long ans = 1LL * p * (n - 1);
        for (int i = 1; i <= n; ++i) {
            if (a[id[i]] >= p) break;
            int cur = id[i];
            while (cur > 1 && a[cur - 1] % a[id[i]] == 0 && get_label(cur - 1) != get_label(id[i])) {
                merge_label(get_label(--cur), get_label(id[i]));
                ans -= p;
                ans += a[id[i]];
            }
            cur = id[i];
            while (cur < n && a[cur + 1] % a[id[i]] == 0 && get_label(cur + 1) != get_label(id[i])) {
                merge_label(get_label(++cur), get_label(id[i]));
                ans -= p;
                ans += a[id[i]];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}