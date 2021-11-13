#include <bits/stdc++.h>

using namespace std;

string read()
{
    cout << "next" << endl;
    cout.flush();
    string x;
    cin >> x;
    return x;
}

int main()
{
    int cnt = 0;
    string ans;
    while (true)
    {
        string x = read();
        if (x == "-1")
        {
            cout << ans << endl;
            cout.flush();
            return 0;
        }
        else if (cnt == 0)
        {
            ans = x;
            cnt = 1;
        }
        else
        {
            if (x == ans)
                ++cnt;
            else
                --cnt;
        }
    }
    return 0;
}