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
    n, k = gai()
    movies = []
    for _ in range(n):
        start, end = gai()
        movies.append((end, start))
    movies.sort()
    res = 0
    ends = [0] * k
    zeroes = k
    for end, start in movies:
        if zeroes == k:
            ends.sort()
        idx = bisect.bisect_right(ends, start)
        if idx == 0:
            continue
        idx -= 1
        ends[idx] = end
        res += 1
        zeroes -= 1
    print(res)
    return


 
test()