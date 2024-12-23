import io,os, sys
from itertools import *
import math
from bisect import *

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
    n, t = gai()
    k = gai()

    def check(mid, n, t, k):
        Sum = 0
        for i in range(n):
            Sum += (mid // k[i])
            if Sum >= t:
                return True
        return False
    
    low, high = 1, min(k) * t
    res = 0
    while low <= high:
        mid = (low + high) // 2
        if check(mid, n, t, k):
            res = mid
            high = mid - 1
        else:
            low = mid + 1
    print(res)

test()