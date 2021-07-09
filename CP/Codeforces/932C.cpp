#include <cstdio>
#include <iostream>

using namespace std;

int n, A, B;

void solve(int x, int y)
{
    int L = 1, R = A;
    while (x--)
    {
        for (int i = L + 1; i <= R; ++i) printf("%d ", i);
        printf("%d ", L);
        L = R + 1; R = L + A - 1;
    }
    R = L + B - 1;
    while (y--)
    {
        for (int i = L + 1; i <= R; ++i) printf("%d ", i);
        printf("%d ", L);
        L = R + 1; R = L + B - 1;
    }
    printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d%d", &n, &A, &B);
    for (int i = 0; i <= n; i += A)
        if ((n - i) % B == 0) { solve(i / A, (n - i) / B); return 0; }
    printf("-1\n");
    return 0;
}
