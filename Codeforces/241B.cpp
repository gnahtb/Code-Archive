#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
 
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
inline bool GetBit(ll x, int i) {
    return x >> i & 1;
}
 
const int N = 50002, LogMax = 30;
const ll Mod = 1e9 + 7;
 
struct Node {
    const static int MaxAdj = 2;
    int cnt;
    Node* adj[MaxAdj];
    int pwc[LogMax + 2];
 
    Node() {
        cnt = 0;
        memset(pwc, 0, sizeof pwc);
        for (int i = 0; i < MaxAdj; ++i)
            adj[i] = nullptr;
    }
};
 
void Ins(int x, Node* cur) {
    for (int i = LogMax; i >= 0; --i) {
        if (cur->adj[GetBit(x, i)] == nullptr)
            cur->adj[GetBit(x, i)] = new Node();
        cur = cur->adj[GetBit(x, i)];
        for (int j = i; j >= 0; --j) {
            cur->pwc[j] += GetBit(x, j);
        }
        ++cur->cnt;
    }
}
 
int Query(ll x, ll y, Node* cur) {
    int ret = 0;
    for (int i = LogMax; i >= 0; --i) {
        if (GetBit(y, i) && cur->adj[GetBit(x, i)] != nullptr) 
            ret += cur->adj[GetBit(x, i)]->cnt;
        if (cur->adj[GetBit(x, i) ^ GetBit(y, i)] == nullptr) break;
        cur = cur->adj[GetBit(x, i) ^ GetBit(y, i)];
    }
    return ret;
}
 
ll Query1(ll x, ll y, Node* cur) {
    ll ret = 0, scu = 0;
    for (int i = LogMax; i >= 0; --i) {
        scu += GetBit(y, i + 1) * (1LL << (i + 1));
        if (GetBit(y, i) && cur->adj[GetBit(x, i)] != nullptr) {
            Node* tmp = cur->adj[GetBit(x, i)];
            ret += (scu) * (tmp->cnt);
            for (int j = i; j >= 0; --j) {
                (ret += (1LL << j) * (GetBit(x, j) ? tmp->cnt - tmp->pwc[j] : tmp->pwc[j])) %= Mod;
            }
        }
        if (cur->adj[GetBit(x, i) ^ GetBit(y, i)] == nullptr) break;
        cur = cur->adj[GetBit(x, i) ^ GetBit(y, i)];
    }
    return ret;
}
 
int n;
ll m, a[N];
Node* root = new Node();
 
bool Greater(int lhs, int rhs) { return lhs > rhs; }
bool GreaterOrEqual(int lhs, int rhs) { return lhs >= rhs; }
 
ll GetCount(int x) {
    ll ret = -n;
    for (int i = 1; i <= n; ++i)
        ret += Query(a[i], x, root);
    return ret / 2;
}
 
pair<ll, ll> Solve(ll x) {
    pair<ll, ll> ret;
    for (int i = LogMax; i >= 0; --i) {
        int tmp = ret.first + (1LL << i);
        ll cur = GetCount(tmp);
        if (x > cur) ret.first += 1LL << i;
    }
    ret.second = GetCount(ret.first);
    return ret;
}
 
int pw[LogMax + 2];
ll sum;
 
int main() {
    ios::sync_with_stdio(false);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        for (int j = 0; j <= LogMax; ++j) {
            (sum += (1LL << j) * (GetBit(a[i], j) ? i - 1 - pw[j] : pw[j])) %= Mod;
            pw[j] += GetBit(a[i], j);
        }
        Ins(a[i], root);
    }
    pair<ll, ll> t1 = Solve(1LL * n * (n - 1) / 2 - m + 1);
    ll tmp = (1LL * n * (n - 1) / 2 - m - t1.second) % Mod * t1.first % Mod;
    (sum += Mod - tmp) %= Mod;
    ll tmp1 = 0;
    for (int i = 1; i <= n; ++i)
        (tmp1 += Query1(a[i], t1.first, root)) %= Mod;
    (tmp1 *= 500000004) %= Mod;
    (sum += Mod - tmp1) %= Mod;
    printf("%lld\n", sum);
    return 0;
}
