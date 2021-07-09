#!/bin/python3

import os
import sys

#
# Complete the fairCut function below.
#
def fairCut(k, arr):
    arr.sort()
    n = len(arr)
    f = [[int(1e18)] * (k + 2) for i in range(n + 2)]
    f[0][0] = 0
    for i in range(1, n + 1):
        for j in range(k + 1):
            # Li does pick
            if j:
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + arr[i - 1] * ((i - j) * 2 - n + k))
            # Li does not pick
            f[i][j] = min(f[i][j], f[i - 1][j] + arr[i - 1] * (j * 2 - k))
    return f[n][k]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    arr = list(map(int, input().rstrip().split()))

    result = fairCut(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()