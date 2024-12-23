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
    w = gai()
    w.sort()
    l, r = 0, len(w) - 1
    res = 0
    while l < r:
        if w[l] + w[r] <= x:
            l += 1
            r -=1
        else:
            r -= 1
        res += 1
    if l == r:
        res += 1
    return res

# for _ in range(int(input())):
print(test())