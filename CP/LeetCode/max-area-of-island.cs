public class Solution {
    int dfs(int i, int j, ref int[][] grid, ref bool[][] avail) {
        if (i < 0 || i >= grid.Length || j < 0 || j >= grid[0].Length || avail[i][j] || grid[i][j] == 0) return 0;
        int res = 1;
        avail[i][j] = true;
        res += dfs(i + 1, j, ref grid, ref avail) + dfs(i - 1, j, ref grid, ref avail) + dfs(i, j + 1, ref grid, ref avail) + dfs(i, j - 1, ref grid, ref avail);
        return res;
    }
    
    public int MaxAreaOfIsland(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        bool[][] avail = new bool[m][];
        for (int i = 0; i < m; ++i)
            avail[i] = new bool[n];
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = Math.Max(res, dfs(i, j, ref grid, ref avail));
            }
        }
        return res;
    }
}