import heapq

n = int(input())

rooms = [i for i in range(1, n + 1)]

intervals = []

for i in range(n):
    start, end = list(map(int, input().split()))
    intervals.append((start, -1, i))
    intervals.append((end, 1, i))

intervals.sort()

assigned = {}

for interval in intervals:
    customer = interval[2]
    if interval[1] == -1:
        assigned[customer] = heapq.heappop(rooms)
    else:
        heapq.heappush(rooms, assigned[customer])

print(max(assigned.values()))

res = []
for i in range(n):
    res.append(str(assigned[i]))
print(" ".join(res))