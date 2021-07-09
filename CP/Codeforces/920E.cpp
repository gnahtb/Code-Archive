#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxN = 2E5 + 5;

int n, m;
vector<int> a[maxN], b, c;
queue<int> q;

void print()
{
    cout << "b = ";
    for (int v: b) cout << v << " ";
    cout << "\n";
}

void solve()
{
    while (b.size())
    {
        q.push(b[0]);
        swap(b[0], b[b.size() - 1]); b.pop_back();
        int k = 1;
        while (!q.empty())
        {
            int u = q.front(), lim = b.size() - 1; q.pop();
            while (lim >= 0)
            {
                bool flag = binary_search(a[u].begin(), a[u].end(), b[0]);
                //cout << b[0] << ": " << flag;
                if (!flag) q.push(b[0]), ++k;
                swap(b[0], b[lim]); swap(b[lim], b[b.size() - 1]);
                if (!flag) b.pop_back();
                --lim;
            }
        }
        c.push_back(k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        b.push_back(i);
        sort(a[i].begin(), a[i].end());
    }
    solve();
    sort(c.begin(), c.end());
    cout << c.size() << "\n";
    for (int v: c) cout << v << " ";
    return 0;
}
