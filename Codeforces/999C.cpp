#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[400005];
bool chk[400005];

void remove()
{
    memset(chk, true, sizeof chk);
    int cnt = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch)
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ch) chk[i] = false, ++cnt;
            if (cnt == k) return;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d%s", &n, &k, &s);
    remove();
    for (int i = 0; i < n; ++i)
        if (chk[i]) printf("%c", s[i]);
    return 0;
}
