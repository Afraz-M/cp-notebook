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

ans = []
x = []
left = []
right = []
A = []
B = []

def test():
    def divi(l, r, v):
        if not v:
            return
        if l == r:
            for i in v:
                ans[i] = x[l]
            return
        
        m = (l + r) // 2

        left[m] = x[m]
        for i in range(m - 1, l - 1, -1):
            left[i] = min(x[i], left[i + 1])

        right[m + 1] = x[m + 1]
        for i in range(m + 2, r + 1):
            right[i] = min(right[i - 1], x[i])

        todo = [[], []]
        for t in v:
            a, b = A[t], B[t]
            if a <= m < b:
                ans[t] = min(min(left[a], x[m]), right[b])
            else:
                todo[1 if a > m else 0].append(t)
                
        divi(l, m, todo[0])
        divi(m + 1, r, todo[1])

    global x, ans, left, right, A, B
    n, q = gai()
    x = gai()
    A, B = [], []
    for _ in range(q):
        a, b = gai()
        A.append(a - 1)
        B.append(b - 1)
    ans = [0] * q
    left = [0] * n
    right = [0] * n
    query_indices = list(range(q))
    divi(0, n - 1, query_indices)
    print("\n".join(map(str, ans)))

test()