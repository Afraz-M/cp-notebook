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
    songs = gai()
    cache = {}
    res, start = 0, 0
    for end in range(n):
        if songs[end] not in cache:
            cache[songs[end]] = end
        else:
            if cache[songs[end]] >= start:
                start = cache[songs[end]] + 1
            cache[songs[end]] = end
        res = max(res, end - start + 1)
    return res
# for _ in range(int(input())):
print(test())