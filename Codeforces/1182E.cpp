#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

struct Matrix {
    vector<vector<ll>> a;

    Matrix() {}

    vector<ll>& operator[](int i) {
        return a[i];
    }

    void SetSize(int h, int w) {
        a.resize(h);
        for (int i = 0; i < h; ++i)
            a[i].resize(w, 0);
    }

    int height() {
        return sz(a);
    }

    int width() {
        return sz(a[0]);
    }
};

Matrix operator*(Matrix& lhs, Matrix& rhs) {
    Matrix res;
    res.SetSize(lhs.height(), rhs.width());
    for (int i = 0; i < lhs.height(); ++i) {
        for (int j = 0; j < rhs.width(); ++j) {
            for (int k = 0; k < lhs.width(); ++k) {
                (res[i][j] += lhs[i][k] * rhs[k][j]) %= (MOD - 1);
            }
        }
    }
    return res;
}

Matrix Power(Matrix a, ll b) {
    Matrix res = a;
    for (--b; b; b >>= 1, a = a * a) if (b & 1) {
        res = res * a;
    }
    return res;
}

ostream& operator<<(ostream& out, Matrix& mat) {
    for (int i = 0; i < mat.height(); ++i) {
        for (int j = 0; j < mat.width(); ++j) {
            out << mat[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

ll Power(ll a, ll b) {
    if (!b) return 1;
    ll t = Power(a, b >> 1);
    t = t * t % MOD;
    if (b & 1) t = t * a % MOD;
    return t;
}

int main() {
    ll n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    Matrix base;
    base.SetSize(3, 3);
    base[0][2] = 1;
    base[1][0] = 1;
    base[1][2] = 1;
    base[2][1] = 1;
    base[2][2] = 1;
    base = Power(base, n - 3);
    Matrix base1;
    base1.SetSize(5, 5);
    base1[1][0] = 1;
    base1[2][1] = 1;
    base1[0][2] = 1;
    base1[1][2] = 1;
    base1[2][2] = 1;
    base1[3][2] = 1;
    base1[4][2] = 1;
    base1[3][3] = 1;
    base1[4][3] = 1;
    base1[4][4] = 1;
    base1 = Power(base1, n - 3);
    Matrix orig;
    orig.SetSize(3, 3);
    orig[0][0] = 1;
    orig[1][1] = 1;
    orig[2][2] = 1;
    Matrix orig1;
    orig1.SetSize(1, 5);
    orig1[0][4] = 2;
    // cout << base1;
    Matrix u = orig * base;
    Matrix u1 = orig1 * base1;
    // cout << u1;
    // printf("c = %lld\n", u1[0][2]);
    ll ans = Power(f1, u[0][2]) * Power(f2, u[1][2]) % MOD * Power(f3, u[2][2]) % MOD * Power(c, u1[0][2]) % MOD;
    cout << ans;
    return 0;
}