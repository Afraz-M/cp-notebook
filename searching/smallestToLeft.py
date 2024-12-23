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
    nums = gai()
    nums = [(i, j) for j, i in enumerate(nums)]
    stack = [nums[0]]
    res = [0] * n
    for i in range(1, n):
        while stack and stack[-1][0] >= nums[i][0]:
            stack.pop()
        if stack:
            res[i] = stack[-1][1] + 1
        stack.append(nums[i])
    for i in res:
        print(f"{i} ")

test()