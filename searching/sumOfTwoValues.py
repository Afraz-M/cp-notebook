import sys

import time

n, target = list(map(int, input().split()))
arr = list(map(int, input().split()))

arr = [(arr[i], i + 1) for i in range(n)]

arr.sort()

l = 0
r = n - 1

while l < r:
    if arr[l][0] + arr[r][0] == target:
        print(arr[l][1], arr[r][1])
        sys.exit()
    
    elif arr[l][0] + arr[r][0] < target:
        l += 1
    else:
        r -= 1

print("IMPOSSIBLE")
