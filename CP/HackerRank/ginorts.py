from itertools import chain

idx = dict()

def init_order():
    current = 0
    for i in chain(range(97, 123), range(65, 91), range(49, 58, 2), range(48, 58, 2)):
        idx[i] = current
        current = current + 1

def sort(s):
    for i in range(len(s)):
        for j in range(i + 1, len(s)):
            if idx[ord(s[i])] > idx[ord(s[j])]:
                s[i], s[j] = s[j], s[i]
    return ''.join(s)
            

if __name__ == '__main__':
    s = input()
    init_order()
    # print(idx)
    print(sort(list(s)))
