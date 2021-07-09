#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int BLK_CNT = 502;
const int BLK_SZ = 600;
const int N = 1e5 + 2;

int cnt[BLK_CNT][N];

int blk_lf(int i) {
    return (i - 1) * BLK_SZ + 1;
}

int blk_rg(int i) {
    return i * BLK_SZ;
}

int blk_idx(int i) {
    return (i - 1) / BLK_SZ + 1;
}

int n, a[N * 3], nx[N * 3], ans[N * 3];
vector<int> v;
stack<int> st;

int idx(int x) {
    return (lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
}

int fd(int x) {
    int lf = 1, rg = sz(v), ret = 0;
    while (lf <= rg) {
        int md = (lf + rg) / 2;
        if (v[md - 1] < x) {
            ret = md;
            lf = md + 1;
        } else rg = md - 1;
    }
    return ret;
}

void prep(int x, int l, int r) {
    int tmp = (a[x] + 1) / 2, tt = fd(tmp);
    int bl = blk_idx(l), br = blk_idx(r);
    for (int i = x; i <= min(r, blk_rg(bl)); ++i)
        if (a[i] < tmp) {
            ans[x] = i;
            return;
        }
//    if (bl == br) return;
    int po = -1;
    for (int i = bl + 1; i < br; ++i) {
        if (cnt[i][tt] > 0) {
            po = i;
            break;
        }
    }
    if (po > 0) {
        for (int i = blk_lf(po); i <= blk_rg(po); ++i) {
            if (a[i] < tmp) {
                ans[x] = i;
                return;
            }
        }
    }
    for (int i = max(blk_rg(bl) + 1, blk_lf(br)); i <= r; ++i)
        if (a[i] < tmp) {
            ans[x] = i;
            return;
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[n + n + i] = a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n * 3; ++i) {
        int po = idx(a[i]);
        ++cnt[blk_idx(i)][po];
    }
    for (int i = 1; blk_lf(i) <= n * 3; ++i) {
        for (int j = 1; j <= sz(v); ++j)
            cnt[i][j] += cnt[i][j - 1];
    }
    a[n * 3 + 1] = INT_MAX;
    st.push(n * 3 + 1);
    for (int i = n * 3; i; --i) {
        while (a[st.top()] < a[i]) st.pop();
        nx[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n * 3; ++i) {
        ans[i] = nx[i];
        prep(i, i, nx[i] - 1);
    }
    for (int i = n * 3; i; --i) {
        if (nx[i] <= n * 3 && ans[i] == nx[i])
            ans[i] = ans[nx[i]];
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] > n * 3) {
            cout << "-1 ";
        } else {
            cout << (ans[i] - i) << " ";
        }
    }
    return 0;
}
