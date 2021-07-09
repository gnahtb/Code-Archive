#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define sqr(a) (a) * (a)

struct TEdge { int u, v, w; };

const int limit = 2E6;

int n, m, mstw = 2;
bool p[limit];
vector<TEdge> e;

void solve()
{
	memset(p, true, sizeof p);
	for (int i = 2; i <= 1000; ++i)
		if (p[i]) for (int j = sqr(i); j <= 1000000; j += i) p[j] = false;
	e.push_back({1, n, 2});
	for (int i = 1; i < n - 2; ++i)
		e.push_back({i, i + 1, 1}), ++mstw;
	if (m > 1)
	{
		int tmp = 1;
		while (!p[mstw + tmp]) ++tmp;
		e.push_back({n - 2, n - 1, tmp});
		mstw += tmp;
		m -= n - 1; if (!m) return;
		for (int i = 1; i <= n; ++i)
		{
			int lim = n, start = i + 2;
			if (i == 1) lim = n - 1;
			if (i == n - 1) start = i + 1;
			for (int j = start; j <= lim; ++j)
			{
				e.push_back({i, j, 1000000});
				--m;
				if (!m) return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	solve();
	printf("%d %d\n", 2, mstw);
	for (int i = 0; i < e.size(); ++i)
		printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
	return 0;
}
