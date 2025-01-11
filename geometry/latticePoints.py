from math import *
from functools import cmp_to_key

n = int(input())
points = []
for _ in range(n):
    points.append(tuple(map(int, input().split())))
points.append(points[0])

area = 0

for i in range(n):
    pi = points[i]
    p1 = points[i + 1]

    area += (pi[0] * p1[1] - p1[0] * pi[1])

area = abs(area)

boundaryPoints = 0
for edgeIdx in range(n):
    p1 = points[edgeIdx]
    p2 = points[edgeIdx + 1]

    if p1[0] == p2[0]:
        boundaryPoints += abs(p1[1] - p2[1])
    elif p1[1] == p2[1]:
        boundaryPoints += abs(p1[0] - p2[0])
    else:
        boundaryPoints += gcd(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]))

insidePoints = (area - boundaryPoints + 2) // 2

print(f"{insidePoints} {boundaryPoints}")