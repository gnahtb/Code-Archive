class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        
        adj = [([False] * n) for i in range(n)]
        for u, v in edges:
            adj[u][v] = adj[v][u] = True
        avail = [True] * n
        
        def dfs(u):
            avail[u] = False
            for v in range(n):
                if avail[v] and adj[u][v]:
                    dfs(v)
        
        comp = 0
        for u in range(n):
            if avail[u]:
                comp = comp + 1
                dfs(u)
        
        return comp