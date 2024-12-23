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
        books= gai()
        books.sort()
        largest = books[-1]
        Sum = sum(books) - largest
        if Sum >= largest:
              res = Sum + largest
        else:
              res = 2 * largest
        print(res)

test()