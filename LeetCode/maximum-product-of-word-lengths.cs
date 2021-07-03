public class Solution {
    public int MaxProduct(string[] words) {
        int res = 0;
        foreach (string s in words)
            foreach (string t in words) {
                bool flag = true;
                for (char i = 'a'; i <= 'z'; ++i)
                    if (s.Contains(i) && t.Contains(i)) {
                        flag = false;
                        break;
                    }
                if (flag) res = Math.Max(res, s.Length * t.Length);
            }
        return res;
    }
}