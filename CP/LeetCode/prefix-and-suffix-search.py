import copy

class WordFilter:

    def __init__(self, words: List[str]):
        self.data = dict()
        for index, word in enumerate(words):
            for i in range(len(word)):
                for j in range(len(word)):
                    prefix = word[:i + 1]
                    suffix = word[j:]
                    if prefix not in self.data:
                        self.data[prefix] = dict()
                    self.data[prefix][suffix] = index
        

    def f(self, prefix: str, suffix: str) -> int:
        if prefix not in self.data:
            return -1
        if suffix not in self.data[prefix]:
            return -1
        return self.data[prefix][suffix]