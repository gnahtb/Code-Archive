public class Solution {
    public bool IsInterleave(string s1, string s2, string s3) {
        if (s3.Length != s1.Length + s2.Length) return false;
        bool[] f = new bool[s2.Length + 3];
        f[0] = true;
        for (int i = 0; i <= s1.Length; ++i) {
            bool[] ft = new bool[s2.Length + 3];
            for (int j = 0; j <= s2.Length; ++j) if (f[j]) {
                if (i < s1.Length && s3[i + j] == s1[i])
                    ft[j] = true;
                if (j < s2.Length && s3[i + j] == s2[j])
                    f[j + 1] = true;
            }
            if (i < s1.Length) f = ft;
        }
        return f[s2.Length];
    }
}