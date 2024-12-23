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
    x, n = gai()  
    p = gai()    
    sortedP = sorted(p)
    base = 0
    max_gap = 0
    for i in sortedP:
        gap = i - base
        max_gap = max(max_gap, gap)
        base = i
    max_gap = max(max_gap, x - base) 
    res = [max_gap]

    current_lights = set(sortedP)
    for i in reversed(p):
        current_lights.remove(i)
        sorted_lights = sorted(current_lights)
        max_gap = 0
        base = 0
        for j in sorted_lights:
            gap = j - base
            max_gap = max(max_gap, gap)
            base = j
        max_gap = max(max_gap, x - base)
        res.append(max_gap)

    res.reverse()
    for i in res[1:]:
        print(f"{i} ")

# for _ in range(int(input())):
test()