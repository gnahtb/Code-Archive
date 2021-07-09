#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)

struct TTrieNode
{
    int cnt = 0;
    TTrieNode *link[2] = { NULL, NULL };
};

const int lim = 1005;

int n, m, v[lim], u[lim], ans = 0;
TTrieNode *root = new TTrieNode();

template <typename T>
void maximize(T &a, T b) { if (a < b) a = b; }

int getBit(int b, int i) { return b >> i & 1; }

void add(int x)
{
    TTrieNode *cur = root;
    for (int i = 28; i >= 0; --i)
    {
        if (cur -> link[getBit(x, i)] == NULL)
            cur -> link[getBit(x, i)] = new TTrieNode();
        cur = cur -> link[getBit(x, i)];
        ++(cur -> cnt);
    }
}

int findMax(int x)
{
    int ret = 0;
    TTrieNode *cur = root;
    for (int i = 28; i >= 0; --i)
    {
        int tmp = getBit(x, i);
        if (cur -> link[tmp ^ 1] != NULL) ret += 1 << i, tmp ^= 1;
        cur = cur -> link[tmp];
    }
    return ret;
}

void enter()
{
    v[0] = u[0] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]), v[i] ^= v[i - 1];
    for (int i = 1; i <= m; ++i)
        scanf("%d", &u[i]), u[i] ^= u[i - 1];
}

void solve()
{
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
        {
            if (odd(r - l)) maximize(ans, v[r] ^ v[l - 1]);
            if (!odd(r - l)) add(v[r] ^ v[l - 1]);
        }
    for (int l = 1; l <= m; ++l)
        for (int r = l; r <= m; ++r)
        {
            if (odd(r - l)) maximize(ans, u[r] ^ u[l - 1]);
            if (!odd(r - l)) maximize(ans, findMax(u[r] ^ u[l - 1]));
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    enter();
    solve();
    printf("%d\n", ans);
    return 0;
}