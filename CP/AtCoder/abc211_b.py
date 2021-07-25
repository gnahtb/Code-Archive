s1 = input()
s2 = input()
s3 = input()
s4 = input()
clgt = set()
clgt.add(s1)
clgt.add(s2)
clgt.add(s3)
clgt.add(s4)
ans = 'Yes'
for i in ['H', '2B', '3B', 'HR']:
    if i not in clgt:
        ans = 'No'
        break
print(ans)