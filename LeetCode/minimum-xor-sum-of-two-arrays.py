class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        
        def cnt_bit(m):
            res = 0
            for i in range(n):
                res += (m >> i) & 1
            return res
        
        f = [[1000000000] * ((1 << n) + 2) for i in range(n + 1)]
        f[0][0] = 0
        for i in range(n):
            for m in range(1, 1 << n):
                for j in range(n):
                    if ((m >> j) & 1) == 1:
                        f[i + 1][m] = min(f[i + 1][m], f[i][m ^ (1 << j)] + (nums2[i] ^ nums1[j]))
        return f[n][(1 << n) - 1]