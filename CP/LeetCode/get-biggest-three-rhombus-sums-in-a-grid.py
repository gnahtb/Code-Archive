class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        
        def get_sum(si, sj, ei, ej, di, dj):
            res = 0
            while si != ei and sj != ej:
                res += grid[si][sj]
                si += di
                sj += dj
            return res
        
        m = len(grid)
        n = len(grid[0])
        res = set()
        for i in range(m):
            for j in range(n):
                res.add(grid[i][j])
        for r in range(1, min(m, n)):
            for i in range(m):
                for j in range(n):
                    if i - r >= 0 and i + r < m and j - r >= 0 and j + r < n:
                        cur = get_sum(i - r, j, i, j - r, 1, -1)
                        cur += get_sum(i, j - r, i + r, j, 1, 1)
                        cur += get_sum(i + r, j, i, j + r, -1, 1)
                        cur += get_sum(i, j + r, i - r, j, -1, -1)
                        res.add(cur)
        resl = list(res)
        resl.sort(reverse=True)
        return resl[:3]