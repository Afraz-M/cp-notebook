import sys
 
n, x = list(map(int, input().split()))
arr = list(map(int, input().split()))
 
arr = [(ele, i) for i, ele in enumerate(arr)]
arr.sort()
 
def kSum(k, arr, target, soln):
    if k == 2:
        l, r = 0, len(arr) - 1
        while l in soln: l += 1
        while r in soln: r -= 1
 
        while l < r:
            if arr[l][0] + arr[r][0] == target:
                soln.append(l)
                soln.append(r)
                return True
            
            elif arr[l][0] + arr[r][0] < target:
                l += 1
                while l in soln: l += 1
            
            else:
                r -= 1
                while r in soln: r -= 1
        
        return False
    
    i = 0
    while i < len(arr):
        if i in soln:
            i += 1
            continue
 
        soln.append(i)
        if kSum(k - 1, arr, target - arr[i][0], soln):
            return True
        soln.pop()
 
        i += 1
    
    return False
 
soln = []
ret = kSum(3, arr, x, soln)
 
if not ret:
    print("IMPOSSIBLE")
else:
    for i in soln:
        print(arr[i][1] + 1, end=" ")