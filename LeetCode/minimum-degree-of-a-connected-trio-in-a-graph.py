class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        ans = 100000000
        adj = []
        deg = {}
        
        def inc_deg(u):
            if u not in deg:
                deg[u] = 0
            deg[u] += 1
        
        for u in range(n):
            adj.append([False] * n)
        for u, v in edges:
            adj[u - 1][v - 1] = True
            adj[v - 1][u - 1] = True
            inc_deg(u - 1)
            inc_deg(v - 1)
        for u1 in range(n):
            for u2 in range(u1 + 1, n):
                for u3 in range(u2 + 1, n):
                    if adj[u1][u2] and adj[u2][u3] and adj[u3][u1]:
                        current_deg = deg[u1] + deg[u2] + deg[u3] - 6
                        ans = min(ans, current_deg)
        if ans > 10000000:
            ans = -1
        return ans
