#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2E5 + 5;

int n, f[N][5], ans = 0;
vector<int> a[N];

void DFS(int u, int p) {
  bool child = false;
  f[u][1] = p != 1; f[u][3] = INT_MAX;
  for (int v : a[u]) if (v != p) {
    DFS(v, u);
    child = true;
    f[u][1] += min(f[v][1], f[v][2]);
    f[u][2] += min(f[v][1], f[v][3]);
  }
  if (!child) return;
  for (int v : a[u]) if (v != p)
    f[u][3] = min(f[u][3], f[u][2] - min(f[v][1], f[v][3]) + f[v][1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v); a[v].push_back(u);
  }
  for (int v : a[1]) DFS(v, 1), ans += f[v][1];
  printf("%d\n", ans);
  return 0;
}
