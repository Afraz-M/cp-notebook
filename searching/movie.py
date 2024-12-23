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
    movies = []
    for _ in range(n):
        start, end = gai()
        movies.append([end, start])
    movies.sort()
    res = 0
    prevEnd = 0
    for end, start in movies:
        if start >= prevEnd:
            res += 1
            prevEnd = end
    print(res)

# for _ in range(int(input())):
test()