class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        
        def isPredecessor(a, b):
            if len(b) != len(a) + 1:
                return False
            for i in range(len(a)):
                if a[:i] == b[:i] and a[i:] == b[i + 1:]:
                    return True
            if a == b[:len(a)]:
                return True
            return False
        
        f = [1] * len(words)
        words.sort(key=lambda x: len(x))
        for i in range(len(words)):
            for j in range(i):
                if isPredecessor(words[j], words[i]):
                    f[i] = max(f[i], f[j] + 1)
        return max(f)