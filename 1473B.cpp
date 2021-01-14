#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s, t;
        cin >> s >> t;
        string cur = "";
        bool ok = false;
        for (int i = 0; i < 20; ++i)
        {
            cur += s;
            if (cur.size() % t.size() == 0)
            {
                bool ok1 = true;
                for (int j = 0; j < (int)cur.size(); ++j)
                    if (cur[j] != t[j % t.size()])
                    {
                        ok1 = false;
                        break;
                    }
                if (ok1)
                {
                    cout << cur << "\n";
                    ok = true;
                    break;
                }
            }
        }
        if (!ok)
            cout << "-1\n";
    }
    return 0;
}