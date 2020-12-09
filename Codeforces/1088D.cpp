#include <bits/stdc++.h>

using namespace std;

int a, b;

inline void query(int c, int d, int &ans) {
    printf("? %d %d\n", c, d);
    fflush(stdout);
    scanf("%d", &ans);
}

void sol(int i, int c1) {
    if (i < 0) {
        printf("! %d %d\n", a, b);
        fflush(stdout);
        return;
    }
    int pw2 = 1 << i, c2;
    if (c1 < -1 || c1 > 1) query(a, b, c1);
    if (c1 == 0) {
        query(a + pw2, b, c2);
        int t = c2 == 1 ? 0 : 1;
        a += t * pw2;
        b += t * pw2;
        sol(i - 1, 0);
    } else {
        query(a + pw2 - 1, b + pw2 - 1, c2);
        if (c1 * c2 == 1) {
            if (c1 == 1) a += pw2;
            else b += pw2;
            sol(i - 1, -2);
        } else {
            int c3;
            query(a + pw2, b, c3);
            int t = c3 == 1 ? 0 : 1;
            a += t * pw2;
            b += t * pw2;
            sol(i - 1, c1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    sol(29, -2);
    return 0;
}
