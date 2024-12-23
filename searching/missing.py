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
    coins = gai()
    res = 1
    coins.sort()
    for coin in coins:
        if coin > res:
            print(res)
            return 
        res += coin
    print(res)

# for _ in range(int(input())):
test()