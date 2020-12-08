def merge_the_tools(string, k):
    l, r = 0, k
    while r <= len(string):
        occured = set()
        for i in range(l, r):
            if not string[i] in occured:
                print(string[i], end='')
                occured.add(string[i])
        print()
        l = l + k
        r = r + k

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)