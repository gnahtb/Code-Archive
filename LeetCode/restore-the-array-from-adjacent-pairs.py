class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        adjacentNodes = dict()
        
        def addEdge(u, v):
            if u not in adjacentNodes:
                adjacentNodes[u] = list()
            adjacentNodes[u].append(v)
        
        for u, v in adjacentPairs:
            addEdge(u, v)
            addEdge(v, u)
        
        start = -1000000
        visitedNodes = set()
        for node in adjacentNodes:
            if len(adjacentNodes[node]) == 1:
                start = node
                break
        ans = list()
        
        def dfs(u):
            ans.append(u)
            visitedNodes.add(u)
            for v in adjacentNodes[u]:
                if v not in visitedNodes:
                    dfs(v)
        
        dfs(start)
        return ans