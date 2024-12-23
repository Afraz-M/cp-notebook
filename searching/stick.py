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
    n = int(input())
    sticks = gai()
    sticks.sort()
    if n % 2 == 1:
        median = sticks[n // 2]
    else:
        median = sticks[(n // 2) - 1]
    res = 0
    for n in sticks:
        res += abs(n - median)
    print(res)

test()