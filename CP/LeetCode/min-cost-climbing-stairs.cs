public class Solution {
    public int MinCostClimbingStairs(int[] cost) {
        int a = 0, b = cost[0];
        for (int i = 1; i < cost.Length; ++i) {
            int c = Math.Min(a, b) + cost[i];
            a = b;
            b = c;
        }
        return Math.Min(a, b);
    }
}