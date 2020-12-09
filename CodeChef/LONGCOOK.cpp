#include <bits/stdc++.h>

using namespace std;

const int K = 2000;
const int MONTHS = 12;

bool F[K + 2][MONTHS + 2];
int sum[K + 2];

bool LeapYear(int year) {
    if (year % 400 == 0) return true;
    else if (year % 4 == 0 && year % 100 != 0) return true;
    else return false;
}

int CountDays(int year, int month) {
    switch (month) {
        case 1: return 31;
        case 2: return LeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
}

void Prep() {
    int cur = 0;
    for (int i = 1; i <= K; ++i) {
        sum[i] = sum[i - 1];
        for (int j = 1; j <= MONTHS; ++j) {
            int firstfri = -1;
            int lastsun = -1, seclastsun = -1;
            for (int it = 1; it <= CountDays(i, j); ++it) {
                int day = cur + it;
                if (day % 7 == 5 && firstfri < 0) firstfri = day;
                if (day % 7 == 0) {
                    seclastsun = lastsun;
                    lastsun = day;
                }
            }
            F[i][j] = seclastsun - firstfri < 10;
            sum[i] += F[i][j];
            cur += CountDays(i, j);
        }
    }
}

int Solve(int m, int y) {
    int ret = sum[K] * (y / K);
    if (y % K > 0) ret += sum[y % K - 1];
    for (int mm = 1; mm <= m; ++mm) ret += F[y % K][mm];
    return ret;
}

int test;

int main() {
    ios::sync_with_stdio(false);
    Prep();
    cin >> test;
    while (test--) {
        int m1, y1, m2, y2;
        cin >> m1 >> y1 >> m2 >> y2;
        int t1 = Solve(m1, y1), t2 = Solve(m2, y2);
        int ans = t2 - t1 + F[y1 % K][m1];
        cout << ans << "\n";
    }
    return 0;
}