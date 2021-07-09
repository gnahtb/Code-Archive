class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        is_pal = [([True] * n) for i in range(n)]
        # print(is_pal)
        for d in range(n):
            for l in range(n):
                r = l + d
                if r >= n:
                    break
                if s[l] == s[r]:
                    if l + 1 >= n or r - 1 < 0 or is_pal[l + 1][r - 1]:
                        is_pal[l][r] = True
                    else:
                        is_pal[l][r] = False
                else:
                    is_pal[l][r] = False
        
        for i in range(n):
            for j in range(i + 1, n):
                if j < n - 1 and is_pal[0][i] and is_pal[i + 1][j] and is_pal[j + 1][n - 1]:
                    return True
        return False