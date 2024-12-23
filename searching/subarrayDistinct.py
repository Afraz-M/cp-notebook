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
    
    l, res, freq = 0, 0, defaultdict(int)
    for r in range(n):
        freq[nums[r]] += 1
        while len(freq) > k:
            freq[nums[l]] -= 1
            if freq[nums[l]] == 0:
                del freq[nums[l]]
            l += 1
        res += r - l + 1
    
    print(res)

test()