import io,os, sys
from itertools import *
from collections import *
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
    josephus = [i+1 for i in range(n)]
    josephus = deque(josephus)
    flag = 0
    while josephus:
        element = josephus.popleft()
        if flag:
            print(f"{element} ")
        else:
            josephus.append(element)
        flag = not flag
    return

# for _ in range(int(input())):
test()