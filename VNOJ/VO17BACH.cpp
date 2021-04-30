#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ull = unsigned long long;

const int Len = 21, Sum = 200;

int q;
int t;
ull n, k;
string sn, sk;

// 0 -> not smaller
// 1 -> smaller
ull f[Len][Sum][2];

void Prep() {
    string tn = sn;
    reverse(tn.begin(), tn.end());
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int len = 1; len <= sz(sn); ++len) {
        for (int sum = 0; sum < Sum; ++sum) {
            for (int d = 0; d < 10; ++d) if (sum >= d) {
                if (d < tn[len - 1] - '0') {
                    f[len][sum][1] += f[len - 1][sum - d][0];
                    f[len][sum][1] += f[len - 1][sum - d][1];
                } else if (d > tn[len - 1] - '0') {
                    f[len][sum][0] += f[len - 1][sum - d][0];
                    f[len][sum][0] += f[len - 1][sum - d][1];
                } else {
                    f[len][sum][0] += f[len - 1][sum - d][0];
                    f[len][sum][1] += f[len - 1][sum - d][1];
                }
            }
        }
    }
}

int DigitSum(ull x) {
    int ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

ull Q1(int s) {
    ull ret = 0;
    for (int i = 0; i < sz(sn); ++i) {
        for (int d = 0; d < sn[i] - '0'; ++d) if (s >= d) {
            ret += f[sz(sn) - i - 1][s - d][0];
            ret += f[sz(sn) - i - 1][s - d][1];
        }
        s -= sn[i] - '0';
    }
    return ret;
}

ull Q2(int s, string pre) {
    string tn = sn.substr(0, sz(pre));
    ull ret = 0;
    for (int len = 0; len < sz(sn) - sz(pre); ++len) {
        ret += f[len][s][1];
        ret += f[len][s][0];
    }
    if (pre <= tn) {
        ret += f[sz(sn) - sz(pre)][s][1];
        if (pre < tn) ret += f[sz(sn) - sz(pre)][s][0];
    }
    return ret;
}

void Solve0() {
    ull ans = 0;
    int ds = DigitSum(k);
    for (int i = 0; i < ds; ++i)
        ans += Q1(i);
    string pre = "";
    for (int i = 0; i < sz(sk); ++i) {
        if (ds == 0) ++ans;
        for (int d = i == 0; d < sk[i] - '0'; ++d) if (ds >= d) {
            ans += Q2(ds - d, pre + char(d + '0'));
        }
        pre += sk[i];
        ds -= sk[i] - '0';
    }
    cout << ans << "\n";
}

void Solve1() {
    string ans = "";
    for (int sum = 1; sum < Sum; ++sum) {
        ull tmp = Q1(sum);
        if (tmp < k) {
            k -= tmp;
            continue;
        }
        for (int i = 1; i < Len && k > 0; ++i) {
            for (int d = i == 1; d < 10; ++d) {
                tmp = Q2(sum - d, ans + char(d + '0'));
                if (tmp < k) {
                    k -= tmp;
                    continue;
                }
                ans += char(d + '0');
                sum -= d;
                if (sum == 0) --k;
                break;
            }
        }
        break;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        cin >> t >> n >> k;
        ++n;
        sn = to_string(n);
        sk = to_string(k);
        Prep();
        if (t == 0) Solve0();
        else Solve1();
    }
    return 0;
}