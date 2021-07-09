class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix)
        cols = len(matrix[0])
        self.matrix = [([0] * cols) for i in range(rows)]
        for i in range(rows):
            for j in range(cols):
                self.matrix[i][j] = matrix[i][j]
                if i > 0:
                    self.matrix[i][j] += self.matrix[i - 1][j]
                if j > 0:
                    self.matrix[i][j] += self.matrix[i][j - 1]
                if i > 0 and j > 0:
                    self.matrix[i][j] -= self.matrix[i - 1][j - 1]
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        ans = self.matrix[row2][col2]
        if row1 > 0:
            ans -= self.matrix[row1 - 1][col2]
        if col1 > 0:
            ans -= self.matrix[row2][col1 - 1]
        if row1 > 0 and col1 > 0:
            ans += self.matrix[row1 - 1][col1 - 1]
        return ans