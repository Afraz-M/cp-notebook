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
        tasks = []
        for i in range(n):
              task = gai()
              tasks.append(task)
        tasks.sort()
        time = 0
        res = 0
        for t in tasks:
            time += t[0]
            res += (t[1] - time)
        print(res)

test()