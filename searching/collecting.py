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
    n, m = gai()
    nums = gai()

    idx = [0] * (n + 1)
    for i in range(n):
        idx[nums[i]] = i
    res = 1
    for i in range(1, n):
        if idx[i + 1] < idx[i]:
            res += 1
    print(res)

# for _ in range(int(input())):
test()