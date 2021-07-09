class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        temp_xor = 0
        current_xor = 0
        for i in encoded:
            current_xor = current_xor ^ i
            temp_xor = temp_xor ^ current_xor
        for i in range(1, n + 1):
            temp_xor = temp_xor ^ i
        perm = [temp_xor]
        for i in encoded:
            perm.append(i ^ perm[-1])
        return perm