#include <bits/stdc++.h>

using namespace std;

int n;
double p1, f1, g1, h1;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &p1);
        f1 = f1 * (1 - p1) + (f1 - g1) * p1;
        g1 = (g1 + h1 * 2 + 1) * p1;
        f1 += g1;
        (++h1) *= p1;
    }
    printf("%.10lf\n", f1);
    return 0;
}
