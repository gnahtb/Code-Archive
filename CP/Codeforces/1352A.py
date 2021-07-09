test = int(input())
while test > 0:
    n = input()
    terms = []
    for i in range(0, len(n)):
        if n[i] > '0':
            terms.append(n[i] + '0' * (len(n) - i - 1))
    print(len(terms))
    for i in terms:
        print(i, end=' ')
    print()
    test = test - 1
