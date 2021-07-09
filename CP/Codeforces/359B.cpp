#include <cstdio>
#include <iostream>

using namespace std;

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &k);
    int x = 1;
    for (int i = 1; i <= k; ++i)
    {
        printf("%d %d %d %d ", x, x + 1, x + 3, x + 2);
        x += 4;
    }
    for (; x <= n * 2; ++x) printf("%d ", x);
    return 0;
}
