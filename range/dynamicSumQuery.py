import io,os, sys
from itertools import *
import math
import bisect

input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x))

alphs = "abcdefghijklmnopqrstuvwxyz"
digs = "0123456789"

class SegTree:
    def __init__(self, arr, comp, defval) -> None:
        self.arr = arr
        self.comp = comp
        self.n = len(arr)
        self.defval = defval
    
        self.tree = [0 for i in range(2 * self.n)]
 
        for i in range(self.n):
            self.tree[self.n + i] = arr[i]
        
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.comp(self.tree[2 * i], self.tree[2 * i + 1])
    
    def printTree(self):
        print(self.tree)
    
    def rq(self, a, b):
        a += self.n
        b += self.n
 
        s = self.defval
 
        while a < b:
            if a&1:
                s = self.comp(s, self.tree[a])
                a += 1
            if b&1:
                b -= 1
                s = self.comp(s, self.tree[b])
            a >>= 1
            b >>= 1
        
        return s
 
    def uq(self, k, x):
        k += self.n
        self.tree[k] = x
 
        k //= 2
        while k >= 1:
            self.tree[k] = self.comp(self.tree[2 * k], self.tree[2 * k + 1])
            k //= 2


INT_MIN = -1e10
INT_MAX = 1e10
MODVALUE = 10 ** 9 + 7

def gai():
    return list(map(int, input().strip().split()))

def test():
    n, q = gai()
    x = gai()
    def add(a, b): return a + b
    st = SegTree(x, add, 0)
    for _ in range(q):
        t, a, b = gai()
        if t == 1:
            st.uq(a - 1, b)
        else:
            print(f"{st.rq(a - 1, b)}\n")
    return

# for _ in range(int(input())):
test()