#include <bits/stdc++.h>

using namespace std;

struct TNode
{
    int cnt = 0;
    TNode *link[2] = { NULL, NULL };
};

int q;
TNode *root = new TNode();

int getBit(int m, int i) { return m >> i & 1; }

void add(int x)
{
    TNode *cur = root;
    for (int i = 30; i >= 0; --i)
    {
        if (cur -> link[getBit(x, i)] == NULL)
            cur -> link[getBit(x, i)] = new TNode();
        cur = cur -> link[getBit(x, i)];
        ++(cur -> cnt);
    }
}

void del(int x)
{
    TNode *cur = root;
    for (int i = 30; i >= 0; --i)
    {
        --(cur -> link[getBit(x, i)] -> cnt);
        if (!(cur -> link[getBit(x, i)] -> cnt))
        {
            cur -> link[getBit(x, i)] = NULL;
            break;
        }
        cur = cur -> link[getBit(x, i)];
    }
}

int ans(int x)
{
    int ret = 0;
    TNode *cur = root;
    for (int i = 30; i >= 0; --i)
    {
        int tmp = getBit(x, i);
        if (cur -> link[tmp ^ 1] != NULL) ret += 1 << i, tmp ^= 1;
        cur = cur -> link[tmp];
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    add(0);
    scanf("%d\n", &q);
    while (q--)
    {
        char c; int x;
        scanf("%c%d\n", &c, &x);
        switch (c)
        {
            case '+': add(x); break;
            case '-': del(x); break;
            case '?': printf("%d\n", ans(x)); break;
        }
    }
    return 0;
}
