t = int(input())
while t > 0:
    n, k = list(map(int, input().split()))
    if k == 0:
        for i in range(1, n + 1):
            print(i, end=" ")
        print()
    else:
        if n % (k * 2) == 0:
            for i in range(1, n + 1, k * 2):
                for j in range(i, i + k, 1):
                    print(j + k, end=" ")
                for j in range(i + k, i + k * 2, 1):
                    print(j - k, end=" ")
            print()
        else:
            print(-1)
    t -= 1