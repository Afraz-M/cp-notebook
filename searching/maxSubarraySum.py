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
    nums = gai()
    res = nums[0]
    longest = nums[0]
    for i in range(1, n):
        longest = max(longest + nums[i], nums[i])
        res = max(longest, res)
    print(res)

test()