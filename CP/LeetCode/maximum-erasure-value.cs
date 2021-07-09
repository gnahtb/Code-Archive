public class Solution {
    public int MaximumUniqueSubarray(int[] nums) {
        int[] sumNums = new int[nums.Length];
        bool[] app = new bool[10002];
        int maxSum = 0;
        for (int l = 0, r = 0, currentSum = 0; l < nums.Length; ++l) {
            while (r < nums.Length && !app[nums[r]]) {
                app[nums[r]] = true;
                currentSum += nums[r++];
            }
            maxSum = Math.Max(maxSum, currentSum);
            app[nums[l]] = false;
            currentSum -= nums[l];
        }
        return maxSum;
    }
}