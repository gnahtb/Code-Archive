test = int(input())
for itest in range(1, test + 1):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    last_num = '0'
    for i in range(n):
        if int(last_num) < a[i]:
            last_num = str(a[i])
        else:
            if str(a[i]) > last_num:
                last_num = str(a[i]) + '0' * max(len(last_num) - len(str(a[i])), 0)
                ans = ans + len(last_num) - len(str(a[i]))
            elif last_num.startswith(str(a[i])):
                tmp_num = str(int(last_num) + 1)
                if tmp_num.startswith(str(a[i])):
                    last_num = tmp_num
                    ans = ans + len(last_num) - len(str(a[i]))
                else:
                    last_num = str(a[i]) + '0' * max(len(last_num) + 1 - len(str(a[i])), 0)
                    ans = ans + len(last_num) - len(str(a[i]))
            else:
                last_num = str(a[i]) + '0' * (len(last_num) + 1 - len(str(a[i])))
                ans = ans + len(last_num) - len(str(a[i]))
    print(f'Case #{itest}: {ans}')
    test = test - 1
