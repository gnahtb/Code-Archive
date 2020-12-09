#include <bits/stdc++.h>
 
using namespace std;
 
int q;
int last = 0;
 
unordered_map<int, int> lab, path;
 
void Exist(int x) {
    if (lab.find(x) == lab.end()) {
        lab[x] = -1;
        path[x] = 0;
    }
}
 
int GetRoot(int u) {
    if (lab[u] < 0) return u;
    int tmp = GetRoot(lab[u]);
    path[u] ^= path[lab[u]];
    lab[u] = tmp;
    return tmp;
}
 
void Merge(int u, int v, int x) {
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    path[v] = x;
}
 
int main() {
    ios::sync_with_stdio(false);
    scanf("%d", &q);
    while (q--) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        l ^= last;
        r ^= last;
        if (l > r) swap(l, r);
        ++r;        
        Exist(l);
        Exist(r);
        int rl = GetRoot(l), rr = GetRoot(r);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            x ^= last;
            if (rl != rr) {
                int tmp = path[l] ^ path[r] ^ x;
                Merge(rl, rr, tmp);
            }
        } else {
            if (rl == rr) {
                int tmp = path[l] ^ path[r];
                last = tmp;
                printf("%d\n", tmp);
            } else {
                printf("-1\n");
                last = 1;
            }
        }
    }
    return 0;
}
