#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int limit = 1E6 + 5;

int n, A, cnt[limit];
bool chk[limit];

int main()
{
    ios_base::sync_with_stdio(false);
    memset(cnt, 0, sizeof cnt);
    memset(chk, true, sizeof chk);
    scanf("%d%d", &n, &A);
    for (int i = 0; i < n; ++i)
    {
        int c;
        scanf("%d", &c);
        if (c != A && cnt[c] < cnt[A]) chk[c] = false;
        ++cnt[c];
    }
    for (int i = 1; i <= 1E6; ++i) if (i != A && cnt[i] < cnt[A]) chk[i] = false;
    for (int i = 1; i <= 1E6; ++i) if (i != A && chk[i]) { printf("%d\n", i); return 0; }
    printf("-1\n");
    return 0;
}
