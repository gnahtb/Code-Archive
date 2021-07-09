#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n, m, ans = 0;
queue<int> c, a;

main() {
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        c.push(t);
    }
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        a.push(t);
    }
    while (!c.empty() && !a.empty()) {
        if (c.front() <= a.front()) ++ans, a.pop();
        c.pop();
    }
    printf("%d\n", ans);
}
