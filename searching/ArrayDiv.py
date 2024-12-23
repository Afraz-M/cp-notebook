import io,os, sys
from itertools import *
import math
import bisect
from collections import *

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
    n, k = gai()
    nums = gai()
    
    def check(x):
        Sum = 0
        partition = 1
        for i in range(n):
            Sum += nums[i]
            if Sum > x:
                Sum = nums[i]
                partition += 1
        return partition <= k
    res = 0
    l, h = max(nums), sum(nums)
    while l <= h:
        mid = (l + h) // 2
        if check(mid):
            res = mid
            h = mid - 1
        else:
            l = mid + 1
    print(res)

test()