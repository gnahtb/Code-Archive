#include <cstdio>
#include <iostream>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
    if (n % 4 == 0)
    {
        printf("0\n");
        printf("%d ", n / 2);
        for (int i = 1; i <= n / 2; i += 2) printf("%d %d ", i, n - i + 1);
    }
    if (n % 4 == 1)
    {
        printf("1\n");
        printf("%d 1 ", n / 2 + 1);
        for (int i = 2; i <= n / 2; i += 2) printf("%d %d ", i, n - i + 2);
    }
    if (n % 4 == 2)
    {
        printf("1\n");
        printf("%d 1 ", n / 2);
        for (int i = 3; i <= n / 2 + 1; i += 2) printf("%d %d ", i, n - i + 3);
    }
    if (n % 4 == 3)
    {
        printf("0\n");
        printf("%d 1 2 ", n / 2 + 1);
        for (int i = 4; i <= n / 2 + 1; i += 2) printf("%d %d ", i, n - i + 4);
    }
	return 0;
}
