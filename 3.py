from collections import defaultdict, deque

n = int(input())
adj = defaultdict(list)
for i in range(n):
    paths = input().split()
    for i in range(1, len(paths)):
        adj[paths[i]].append(paths[0])
adj["warehouse"] = []
item = input().split()
weights = list(map(int, input().split()))
s = int(input())
switched = defaultdict(int)
opened = defaultdict(str)
res = 0
paths = []
for _ in range(len(item)):
    i = item[_]
    q = deque([i])
    temp = []
    while q:
        jun1 = q.pop()
        temp.append(jun1)
        for i in adj[jun1]:
            q.append(i)
    paths.append(temp)

for j in range(len(paths)):
    path = paths[j]
    temp = opened.copy()
    for i in range(1, len(path)):
        if opened[path[i]] == path[i - 1]:
            continue
        if switched[path[i]] == s:
            res += weights[j]
            opened = temp
            break
        opened[path[i]] = path[i - 1]
        switched[path[i]] += 1

print(res)
        


