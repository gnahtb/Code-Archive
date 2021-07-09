public class Solution {
    public int MinCost(int[][] costs) {
        int[][] f = new int[costs.Length][];
        f[0] = costs[0];
        for (int i = 1; i < costs.Length; ++i) {
            f[i] = new int[3];
            f[i][0] = Math.Min(f[i - 1][1], f[i - 1][2]) + costs[i][0];
            f[i][1] = Math.Min(f[i - 1][0], f[i - 1][2]) + costs[i][1];
            f[i][2] = Math.Min(f[i - 1][1], f[i - 1][0]) + costs[i][2];
        }
        return Math.Min(Math.Min(f[costs.Length - 1][0], f[costs.Length - 1][1]), f[costs.Length - 1][2]);
    }
}