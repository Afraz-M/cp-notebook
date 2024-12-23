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
    times = []
    for _ in range(n):
        arrival, leaving = gai()
        times.append([arrival, 1])
        times.append([leaving, -1])
    times.sort()
    res = 0
    temp = 0
    for time, i in times:
        temp += i
        res = max(res, temp)
    print(res)
    return

# for _ in range(int(input())):
test()