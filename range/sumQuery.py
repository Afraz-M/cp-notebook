import io,os, sys
from itertools import *
import math
import bisect

input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x))

alphs = "abcdefghijklmnopqrstuvwxyz"
digs = "0123456789"

INT_MIN = -1e10
INT_MAX = 1e10
MODVALUE = 10 ** 9 + 7

def gai():
    return list(map(int, input().strip().split()))

def test():
    n, x = gai()
    arr = gai()
    prefix = [0] * (n + 1)
    Sum = 0
    for i in range(0, n):
        Sum += arr[i]
        prefix[i + 1] = Sum
    res = []
    for i in range(x):
        a, b = gai()
        res.append(prefix[b] - prefix[a - 1])
    return res


for i in test():
    print(f"{i}\n")