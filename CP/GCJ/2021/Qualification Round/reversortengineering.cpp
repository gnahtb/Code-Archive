#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int test, n, c, L[N];

int main() {
    scanf("%d", &test);
    for (int itest = 1; itest <= test; ++itest) {
        scanf("%d%d", &n, &c);
        if (c < n - 1) {
            printf("Case #%d: IMPOSSIBLE\n", itest);
            continue;    
        }
        c -= n - 1;
        for (int i = 0; i < n; ++i) L[i] = i + 1;
        for (int i = n - 2; i >= 0; --i) {
            int tmp = min(c, n - i - 1);
            int j1 = i, j2 = i + tmp;
            while (j1 < j2) swap(L[j1], L[j2]), ++j1, --j2;
            c -= tmp;
        }
        printf("Case #%d: ", itest);
        if (c == 0) for (int i = 0; i < n; ++i) printf("%d ", L[i]);
        else printf("IMPOSSIBLE");
        printf("\n");
    }
    return 0;
}