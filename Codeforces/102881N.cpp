#include <bits/stdc++.h>

int main() {
    freopen("equal.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == b || b == c || c == a) puts("YES"); else puts("NO");
    }
    return 0;
}