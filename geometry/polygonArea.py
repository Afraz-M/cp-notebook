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

print(abs(area))