tests = int(input())
while tests > 0:
    n = int(input())
    a = map(int, input().split())
    cnt = dict()
    for i in a:
        if i not in cnt:
            cnt[i] = 0
        cnt[i] = cnt[i] + 1
    flag = False
    for i in cnt:
        if cnt[i] > 1:
            flag = True
    if not flag:
        print("First")
    else:
        if n % 2 == 0:
            print("Second")
        else:
            print("First")
    tests = tests - 1