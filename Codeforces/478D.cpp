#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define reset(a) memset(a, 0, sizeof(a))

const int mod = 1e9+7;

int r, g, ans = 0, f[200005];

int main()
{
  ios_base::sync_with_stdio(false);
  cin >> r >> g;
  int h = 1;
  while ((h+1)*(h+2)/2 <= r+g) ++h;
  reset(f);
  f[0] = 1;
  for (int i = 1; i <= h; ++i)
    for (int j = r; j >= 0; j--)
    {
      if (j >= i) f[j] += f[j-i];
      f[j] %= mod;
    }
  
  for (int i = 0; i <= r; ++i)
    if (h*(h+1)/2 <= i+g)
    {
      ans += f[i];
      ans %= mod;
    }
  cout << ans;
  return 0;
}
