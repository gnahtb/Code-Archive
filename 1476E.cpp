#include <bits/stdc++.h>

using namespace std;

const int N = 10 + 2;
const int K = 4;

int n, m, k, mt[N], deg[N];
string p[N], s[N];
vector<int> ans;
map<string, int> pid;
vector<int> q[N];
priority_queue<pair<int, int>> pq;
bool vis[N];

bool get_bit(int bmask, int i) {
  return bmask >> i & 1;
}

int get_pid(string& key) {
  auto it = pid.find(key);
  if (it == pid.end()) return -1;
  return it->second;
}

int main() {
  freopen("inp.txt", "r", stdin);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    pid[p[i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> s[i] >> mt[i];
    for (int j = 0; j < k; ++j) {
      if (p[mt[i]][j] != s[i][j] && p[mt[i]][j] != '_') {
        cout << "NO";
        return 0;
      }
    }
    ++deg[mt[i]];
    q[mt[i]].push_back(i);
    for (int bmask = 0; bmask < 1 << k; ++bmask) {
      string key = s[i];
      for (int j = 0; j < k; ++j) if (get_bit(bmask, j)) {
        key[j] = '_';
      }
      int pid = get_pid(key);
      if (pid > 0 && !vis[pid]) {
        --deg[pid];
      }
    }
  }
  for (int i = 1; i <= n; ++i) pq.emplace(deg[i], i);
  vector<int> ans;
  while ((int)ans.size() < n) {
    if (pq.top().first < 0) {
      cout << "NO";
      return 0;
    }
    int i = pq.top().second;
    pq.pop();
    if (vis[i]) continue;
    vis[i] = true;
    ans.push_back(i);
    for (int j : q[i]) {
      for (int bmask = 0; bmask < 1 << k; ++bmask) {
        string key = s[j];
        for (int j1 = 0; j1 < k; ++j1) if (get_bit(bmask, j1)) {
          key[j1] = '_';
        }
        int pid = get_pid(key);
        if (pid > 0) {
          ++deg[pid];
          pq.emplace(deg[pid], pid);
        }
      }
    }
  }
  cout << "YES\n";
  for (int i : ans) cout << i << " ";
  return 0;
}