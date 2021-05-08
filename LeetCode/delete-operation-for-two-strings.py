class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        f = [([0] * (len(word2) + 2)) for i in range(len(word1) + 2)]
        for i in range(len(word1)):
            for j in range(len(word2)):
                if word1[i] == word2[j]:
                    f[i + 1][j + 1] = f[i][j] + 1
                else:
                    f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1])
        return len(word1) + len(word2) - f[len(word1)][len(word2)] * 2