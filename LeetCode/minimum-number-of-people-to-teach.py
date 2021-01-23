class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        m = len(languages)
        min_students = m
        need_teaching = []
        for i in range(len(friendships)):
            u, v = friendships[i]
            u -= 1
            v -= 1
            friendships[i] = [u, v]
            if len(set(languages[u]) & set(languages[v])) == 0:
                need_teaching.append(True)
            else:
                need_teaching.append(False)
        for languageId in range(1, n + 1):
            learned = [False] * m
            students = 0
            for i in range(len(friendships)):
                if not need_teaching[i]:
                    continue
                u, v = friendships[i]
                if (not learned[u]) and (languageId not in languages[u]):
                    learned[u] = True
                    students += 1
                if (not learned[v]) and (languageId not in languages[v]):
                    learned[v] = True
                    students += 1
            min_students = min(min_students, students)
        return min_students