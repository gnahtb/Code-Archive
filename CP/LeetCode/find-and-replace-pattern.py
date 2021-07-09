class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        
        def differentiate(word):
            chains = []
            for i in range(len(word)):
                flag = False
                for j in range(i):
                    if word[i] == word[j]:
                        flag = True
                        for chain in chains:
                            if j in chain:
                                chain.append(i)
                                break
                        break
                if not flag:
                    chains.append([i])
            return chains
        
        pattern_chains = differentiate(pattern)
        matched_words = []
        for word in words:
            word_chains = differentiate(word)
            flag = True
            for chain in pattern_chains:
                if chain not in word_chains:
                    flag = False
                    break
            if flag:
                matched_words.append(word)
        return matched_words