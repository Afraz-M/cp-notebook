from math import sqrt
from functools import cmp_to_key

class Point:
    def _init_(self, x, y) -> None:
        self.x = x
        self.y = y
    
    def distanceTo(self: "Point", other: "Point") -> float:
        return sqrt((self.x - other.x) * 2 + (self.y - other.y) * 2)
    
    def comp(one: "Point", other: "Point") -> int:
        if one.x < other.x:
            return -1
        elif one.x > other.x:
            return 1
        elif one.y < other.y:
            return -1
        elif one.y > other.y:
            return 1
        else:
            return 0
    
    def _repr_(self) -> str:
        return f"{self.x} {self.y}"

def cross(o: "Point", a: "Point", b: "Point"):
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x)

n = int(input())
points = []

for _ in range(n):
    x, y = list(map(int, input().split()))
    points.append(Point(x, y))

points.sort(key=cmp_to_key(Point.comp))

stack = []
for point in points:
    while len(stack) >= 2 and cross(stack[-2], stack[-1], point) < 0:
        stack.pop()
    stack.append(point)

start = stack[0]
end = stack[-1]

ans = []

for point in reversed(points):
    if point.x == start.x and point.y != start.y:
        ans.append(point)

for point in stack:
    ans.append(point)

peri = 0
anslen = len(ans)
for i in range(anslen - 1):
    p1 = ans[i]
    p2 = ans[i + 1]
    peri += p1.distanceTo(p2)

print(round(peri), end = "")