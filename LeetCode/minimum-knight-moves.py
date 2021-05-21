import heapq

class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        d = [(1, 2), (2, 1), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1)]
        Q = list()
        visitedCells = set()
        heapq.heappush(Q, (0, 0, 0))
        visitedCells.add((0, 0))
        while len(Q):
            dist, i, j = heapq.heappop(Q)
            if (i, j) == (x, y):
                return dist
            for di, dj in d:
                i1, j1 = i + di, j + dj
                if (i1, j1) not in visitedCells and i1 in range(-321, 321) and j1 in range(-321, 321):
                    heapq.heappush(Q, (dist + 1, i1, j1))
                    visitedCells.add((i1, j1))
        return -1