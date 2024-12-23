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
import bisect

def test():
    n , m = gai()
    h = gai()
    t = gai()
    h.sort()
    res = [0 for _ in range(len(t))]
    for i in range(len(t)):
        toAssign = t[i]
        idx = bisect.bisect(h,toAssign)
        if (idx == 0):
            res[i] = -1
        else:
            idx -= 1
            res[i] = h[idx]
            h.remove(res[i])
    for i in res:
        print(f"{i}\n")

test()