#include <bits/stdc++.h>

using namespace std;

int n;
string s, r = "";

bool isVowel(char c)
{
    if (c == 'u') return true;
    if (c == 'e') return true;
    if (c == 'o') return true;
    if (c == 'a') return true;
    if (c == 'i') return true;
    if (c == 'y') return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    r = s[0];
    for (int i = 1; i < n; ++i)
        if ((isVowel(s[i]) && !isVowel(s[i - 1])) || !isVowel(s[i])) r += s[i];
    cout << r << "\n";
    return 0;
}
