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
    n = int(input())
    a = list(map(int, input().split()))
    pref = {i: 0 for i in range(n)}
    c = 0
    s = 0
    for ai in a:
        s += ai
        c += pref[(s % n)]
        if (s % n) == 0:
            c += 1
        pref[(s % n)] += 1
    print(c)


test()