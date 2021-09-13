#include <bits/stdc++.h>

using namespace std;

const int N = 32;

int test, n, k, p[N];

double trau() {
    sort(p, p + n);
    n = unique(p, p + n) - p;
    double ans = 0.0;
    for (int x = 1; x <= k; ++x) {
        for (int y = x + 1; y <= k; ++y) {
            int cnt = 0;
            for (int i = 1; i <= k; ++i) {
                int mindis = INT_MAX;
                for (int j = 0; j < n; ++j) {
                    mindis = min(mindis, abs(i - p[j]));
                }
                if (min(abs(i - x), abs(i - y)) < mindis) ++cnt;
            }
            printf("%d %d %d\n", x, y, cnt);
            ans = max(ans, 1.0 * cnt / k);
        }
    }
    return ans;
}

int main() {
    scanf("%d", &test);
    for (int itest = 1; itest <= test; ++itest) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) scanf("%d", p + i);
        sort(p, p + n);
        n = unique(p, p + n) - p;
        double ans = 0.0;
        vector<int> segs;
        segs.clear();
        for (int i = 0; i + 1 < n; ++i)
            if (p[i + 1] - p[i] > 1) {
                int pm = p[i] + 1;
                int x = (pm + p[i + 1]) / 2;
                while (x - pm <= p[i + 1] - x) ++x;
                while (x - pm >= p[i + 1] - x) --x;
                segs.push_back(x - pm + 1);
                ans = max(ans, 1.0 * p[i + 1] - p[i] - 1);
            }
        segs.push_back(p[0] - 1);
        segs.push_back(k - p[n - 1]);
        sort(segs.begin(), segs.end(), greater<int>());
        ans = max(ans, 1.0 * segs[0] + segs[1]);
        ans /= k;
        printf("Case #%d: %.10lf\n", itest, ans);
        // printf("%.10f\n", trau());
    }
    return 0;
}