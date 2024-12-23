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
    N, X = gai()
    T = gai()
    prefixSum = 0
    res = 0
    prefixMap = {0: 1} 
    for x in T:
        prefixSum += x
        res += prefixMap.get(prefixSum - X, 0)
        prefixMap[prefixSum] = prefixMap.get(prefixSum, 0) + 1
    print(res)

test()