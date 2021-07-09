public class Solution {
    public int[] RunningSum(int[] nums) {
        List<int> res = new List<int>();
        int cur = 0;
        foreach (int i in nums) {
            cur += i;
            res.Add(cur);
        }
        return res.ToArray();
    }
}