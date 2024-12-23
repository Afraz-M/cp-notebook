import sys

n = int(input())
grid = [list(input()) for _ in range(n)]

def validateIntersection(r, c):
    one, two = 0, 0
    for dr, dc in dirs:
        nr, nc = r + dr, c + dc
        if 0 <= nr < n and 0 <= nc < n:
            if grid[nr][nc] == "1":
                one += 1
            elif grid[nr][nc] == "2":
                two += 1
    if one == 2 and two == 2: 
        return grid[r][c] 
    else: return None

dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

begin = None
for r in range(n):
    for c in range(n):
        if grid[r][c] == "1" and not begin:
            begin = (r, c)

dir = None
for dr, dc in dirs:
    nr, nc = begin[0] + dr, begin[1] + dc
    if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == "1":
        dir = (dr, dc)
        break

visited = []
cur = (begin[0] + dir[0], begin[1] + dir[1])
prev = begin

while cur != begin:
    junction = validateIntersection(cur[0], cur[1])
    if junction:
        visited.append(junction)
    
    nr, nc = cur[0] + dir[0], cur[1] + dir[1]
    if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == "2":
        prev, cur = cur, (nr, nc)
    else:
        dir = None
        for dr, dc in dirs:
            nr, nc = cur[0] + dr, cur[1] + dc
            if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == "1" and (nr, nc) != prev:
                dir = (dr, dc)
                break
        if dir:
            prev, cur = cur, (cur[0] + dir[0], cur[1] + dir[1])

stack = []
for junction in visited:
    if stack and stack[-1] == junction:
        stack.pop()
    else:
        stack.append(junction)
    if len(stack) == 3:
        print("Impossible")
        sys.exit()

print("Impossible" if stack else len(visited))
