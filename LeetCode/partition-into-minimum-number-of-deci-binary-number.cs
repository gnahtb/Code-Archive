public class Solution {
    public int MinPartitions(string n) {
        int ret = 0;
        foreach (char i in n) ret = Math.Max(ret, i - '0');
        return ret;
    }
}