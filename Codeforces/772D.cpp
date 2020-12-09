#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

const int PW = 6;
const int LIM = 1000000;
const int BASES[6] = {1, 10, 100, 1000, 10000, 100000};

inline int ith_digit(int x, int i) {
    return x / BASES[i] % 10;
}

struct Data {
    ll n1 = 0;   //number of distinct element

    ll n = 0;    //number of subsets
    ll s = 0;    //sum of subsets
    ll s2 = 0;   //sum of power 2

    int mn = 9999999;   //shit
};

vector<Data> f(LIM);

Data operator +(Data &lhs, Data &rhs) {
    Data ret;

    ret.n1 = lhs.n1 + rhs.n1;

    ret.n = (lhs.n + rhs.n + lhs.n * rhs.n) % MOD;

    ret.s = (lhs.s * rhs.n % MOD + lhs.n * rhs.s % MOD) % MOD;
    (ret.s += lhs.s + rhs.s) %= MOD;

    ret.s2 = (lhs.n * rhs.s2 % MOD + lhs.s2 * rhs.n % MOD) % MOD;
    (ret.s2 += lhs.s * rhs.s % MOD * 2LL % MOD) %= MOD;
    (ret.s2 += (lhs.s2 + rhs.s2) % MOD) %= MOD;

    int tmp = 0;
    for (int i = 0; i < PW; ++i)
        tmp += min(ith_digit(lhs.mn, i), ith_digit(rhs.mn, i)) * BASES[i];
    ret.mn = tmp;

    return ret;
}

ll ans;
//ll s[LIM];

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;

        Data t;
        t.mn = a;
        t.n = 1;
        t.s2 = a * a % MOD;
        t.s = a;

        f[a] = f[a] + t;
    }

    for (int i = 0; i < LIM; ++i) if (f[i].mn == i) f[i].n1 = 1;

    for (int j = 0; j < PW; ++j) {
        for (int i = LIM - 1; i >= 0; --i) {
            if (ith_digit(i, j) < 9) {
                int x = i + BASES[j];
                f[i] = f[i] + f[x];
            }
        }
    }

//    for (int i = 0; i < LIM; ++i)
//        if (f[i].mn == i) {
//            s[i] = f[i].s2;
//            if (f[i].n1 % 2 != 0)
//                s[i] = (MOD - s[i]) % MOD;
////                s[i] *= -1;
//        }

//    for (int j = 0; j < PW; ++j) {
//        for (int i = LIM - 1; i >= 0; --i) {
//            if (ith_digit(i, j) < 9) {
//                int x = i + BASES[j];
//                (s[i] += s[x]) %= MOD;
//            }
//        }
//    }
//    for (int i = 0; i < LIM; ++i) {
//        for (int m = 0; m < 1 << PW; ++m) {
//            int cnt = 0, nx = i;
//            bool chk = true;
//            for (int k = 0; k < PW; ++k) {
//                if (m >> k & 1) {
//                    ++cnt;
////                    int tmp = ith_digit(i, k);
////                    if (tmp == 9) {
////                        chk = false;
////                        break;
////                    } else
//                      nx += BASES[k];
//                }
//            }
//            if (!chk) continue;
//            if (cnt % 2 == 0) (s[i] += f[i].s2) %= MOD;
//            else (s[i] += MOD - f[i].s2) %= MOD;
//        }
//    }
//
//    for (int i = 0; i < LIM; ++i) /*if (f[i].mn == i)*/ {
//        cout << i << " ";
//        cout << f[i].s2 << " ";
//        cout << f[i].n1 << " ";
//        cout << s[i] << " ";
////        ll tmp = s[i];
////        if (f[i].n1 % 2 != 0) tmp = (MOD - tmp) % MOD;
////        cout << tmp;
//
////        tmp *= i;
////        ans ^= tmp;
//
//        cout << endl;
//    }
//
////    cout << ans << "\n";

//    int i = 321;
//    long long sum = 0;
//    for (int m = 0; m < 1 << PW; ++m) {
//        int nx = i;
//        bool cnt = false, chk = true;
//        for (int j = 0; j < PW; ++j)
//            if (m >> j & 1 == 1) {
//                if (ith_digit(i, j) == 9) {
//                    chk = false;
//                    break;
//                }
//                nx += BASES[j];
//                cnt ^= 1;
//            }
//        if (chk) {
//            if (!cnt) sum += f[nx].s2;
//            else sum -= f[nx].s2;
//        }
//    }
//    cout << sum;

    for (int i = 0; i < LIM; ++i) if (f[i].mn == i) {
        long long sum = 0;
        for (int m = 0; m < 1 << PW; ++m) {
            int nx = i;
            bool cnt = false, chk = true;
            for (int j = 0; j < PW; ++j)
                if (m >> j & 1 == 1) {
                    if (ith_digit(i, j) == 9) {
                        chk = false;
                        break;
                    }
                    nx += BASES[j];
                    cnt ^= 1;
                }
            if (chk) {
                if (!cnt) (sum += f[nx].s2) %= MOD;
                else (sum += MOD - f[nx].s2) %= MOD;
            }
        }
        sum *= i;
        ans ^= sum;
    }

    cout << ans << endl;

    return 0;
}
