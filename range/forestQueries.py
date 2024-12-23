import io,os, sys
from itertools import *
import math
import bisect


alphs = "abcdefghijklmnopqrstuvwxyz"
digs = "0123456789"

INT_MIN = -1e10
INT_MAX = 1e10
MODVALUE = 10 ** 9 + 7

def gai():
    return list(map(int, input().strip().split()))



def test():
    n, q = gai()
    forest = []
    for _ in range(n):
        lane = list(input())
        forest.append(lane)
    queries =[ ]
    for _ in range(q):
        y1, x1, y2, x2 = gai()
        queries.append((y1 - 1, x1 - 1, y2 - 1, x2 - 1))
    res = []
    prefix = [[0] * n for _ in range(n)]
    tempRow = tempCol = 0
    def f(row, col):
        if row in range(n) and col in range(n):
            return prefix[row][col]
        else:
            return 0
    for i in range(n):
        tempRow += 1 if forest[i][0] == '*' else 0
        tempCol += 1 if forest[0][i] == '*' else 0
        prefix[i][0] = tempRow
        prefix[0][i] = tempCol
    for i in range(1, n):
        for j in range(1, n):
            tree = 1 if forest[i][j] == '*' else 0
            prefix[i][j] = tree + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]
    for i in queries:
        x1, y1, x2, y2 = i
        res.append(f(x2, y2) - f(x1 - 1, y2)
           - f(x2, y1 - 1) + f(x1 - 1, y1 - 1))
    for i in res:
        print(i)
    return 

# for _ in range(int(input())):
test()