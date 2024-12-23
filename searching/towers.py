import io,os, sys
from itertools import *
import math
from bisect import *

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
    cubes = gai()
    res = 0
    top = []
    for i in range(n):
        idx = bisect_right(top, cubes[i])
        if idx == len(top):
            res += 1
            top.append(cubes[i])
        else:
            top[idx] = cubes[i]        
    return res

# for _ in range(int(input())):
print(test())