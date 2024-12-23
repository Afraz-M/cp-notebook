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
    intervals = []
    for i in range(n):
        i = gai()
        intervals.append(i)
    contained = [0] * n
    contains = [0] * n

    intervals = [(l, r, i) for i, (l, r) in enumerate(intervals)]

    intervals.sort(key=lambda x: (x[0], -x[1]))
    maxR = -float('inf')
    for l, r, i in intervals:
        if r <= maxR:
            contained[i] = 1
        maxR = max(maxR, r)

    minR = float('inf')
    for j in range(n - 1, -1, -1):
        l, r, i = intervals[j]
        if r >= minR:
            contains[i] = 1
        minR = min(minR, r)
    for i in contains:
        print(i)
        print(" ")
    print("\n")
    for i in contained:
        print(i)
        print(" ")
    return
    
 
test()