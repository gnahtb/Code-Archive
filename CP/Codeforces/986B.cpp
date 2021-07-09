#include <bits/stdc++.h>

using namespace std;

const int maxN = 1E6 + 5;

int n, a[maxN];
bool f = false;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
    {
		if (!a[i]) continue;
		f ^= true;
		int x = i;
		while (x) { int y = a[x]; a[x] = 0; x = y; }
	}
    printf(f ? "Um_nik\n" : "Petr\n");
	return 0;
}
