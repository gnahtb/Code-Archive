#include <bits/stdc++.h>

using namespace std;

int n, k = 0;

template <typename T>
void minimize(T &a, T b) { if (a > b) a = b; }

int solve(int a, int b, int c)
{
    if (!(a % b)) return b > 1 ? INT_MAX : c + a / b - 1;
    return solve(b, a % b, c + a / b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    if (n > 1) k = INT_MAX;
    for (int i = 1; i < n; ++i) minimize(k, solve(n, i, 0));
    printf("%d\n", k);
    return 0;
}
