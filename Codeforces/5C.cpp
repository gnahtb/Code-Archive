#include <bits/stdc++.h>

using namespace std;

const int limit = 1E6 + 5;

string s;
stack<int> a;
int f[limit], g[limit], len = 0, cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    memset(f, -1, sizeof f);
    memset(g, 0, sizeof g);
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == '(') { a.push(i); continue; }
        if (a.empty()) continue;
        f[i] = a.top(); a.pop();
        g[i] = i - f[i] + 1 + g[f[i] - 1];
    }
    for (int i = 0; i < (int)s.size(); ++i)
        if (g[i] > len) len = g[i], cnt = 1;
        else if (g[i] == len) ++cnt;
    if (len == 0) cnt = 1;
    cout << len << " " << cnt << "\n";
    return 0;
}
