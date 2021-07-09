public class Solution {
    public int MaxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        Array.Sort(horizontalCuts);
        Array.Sort(verticalCuts);
        int hmax = w - verticalCuts[verticalCuts.Length - 1];
        int vmax = h - horizontalCuts[horizontalCuts.Length - 1];
        for (int i = 0, cur = 0; i < horizontalCuts.Length; ++i) {
            vmax = Math.Max(vmax, horizontalCuts[i] - cur);
            cur = horizontalCuts[i];
        }
        for (int i = 0, cur = 0; i < verticalCuts.Length; ++i) {
            hmax = Math.Max(hmax, verticalCuts[i] - cur);
            cur = verticalCuts[i];
        }
        return Convert.ToInt32(1L * hmax * vmax % 1000000007);
    }
}