public class Solution {
    public int MinRefuelStops(int target, int startFuel, int[][] stations) {
        int[,] dp = new int[502, 502];
        for (int i = 0; i < 502; ++i)
            for (int j = 0; j < 502; ++j)
                dp[i, j] = -1;
        dp[0, 0] = startFuel;
        int n = stations.Length;
        for (int i = 1; i <= n; ++i) {
            int dist = stations[i - 1][0];
            if (i > 1) dist -= stations[i - 2][0];
            for (int j = 0; j <= i; ++j) {
                if (dp[i - 1, j] >= 0) {
                    dp[i, j] = dp[i - 1, j] - dist;
                }
                if (j > 0 && dp[i - 1, j - 1] >= 0 && dp[i - 1, j - 1] >= dist) {
                    dp[i, j] = Math.Max(dp[i, j], dp[i - 1, j - 1] - dist + stations[i - 1][1]);
                }
            }
        }
        int dist_target = target;
        if (n > 0) dist_target -= stations[n - 1][0];
        for (int j = 0; j <= n; ++j)
            if (dp[n, j] >= dist_target) return j;
        return -1;
    }
}