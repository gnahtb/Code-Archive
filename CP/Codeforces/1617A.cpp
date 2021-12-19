#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

int main()
{
    freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        string s, t;
        cin >> s >> t;
        sort(s.begin(), s.end());
        if (t == "abc")
        {
            bool fa = false, fb = false, fc = false;
            for (int i = 0; i < sz(s); ++i)
                if (s[i] == 'a')
                    fa = true;
                else if (s[i] == 'b')
                    fb = true;
                else if (s[i] == 'c')
                    fc = true;
            if (fa && fb && fc)
                sort(s.begin(), s.end(), [](char x, char y)
                    {
                        if (x == 'b' && y == 'c')
                            return false;
                        else if (x == 'c' && y == 'b')
                            return true;
                        else
                            return x < y;
                    });
        }
        cout << s << endl;
    }
    return 0;
}