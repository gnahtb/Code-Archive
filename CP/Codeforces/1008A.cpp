#include <bits/stdc++.h>

using namespace std;

#define sz(a) int(a.size())

string s;

bool isVowel(char x)
{
    if (x == 'u') return true;
    if (x == 'e') return true;
    if (x == 'a') return true;
    if (x == 'o') return true;
    if (x == 'i') return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < sz(s) - 1; ++i)
        if (s[i] != 'n' && !isVowel(s[i]) && !isVowel(s[i + 1])) { cout << "NO\n"; return 0; }
    if (!isVowel(s[sz(s) - 1]) && s[sz(s) - 1] != 'n') { cout << "NO\n"; return 0; }
    cout << "YES\n";
    return 0;
}
