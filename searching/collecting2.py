# import io,os, sys
# from itertools import *
# import math
# import bisect

# input = sys.stdin.readline
# print = lambda x: sys.stdout.write(str(x))

# alphs = "abcdefghijklmnopqrstuvwxyz"
# digs = "0123456789"

# INT_MIN = -1e10
# INT_MAX = 1e10
# MODVALUE = 10 ** 9 + 7

# def gai():
#     return list(map(int, input().strip().split()))

# def test():
#     n, m = gai()
#     nums = gai()

#     idx = [0] * (n + 1)
#     for i in range(n):
#         idx[nums[i]] = i
#     res = 1
#     for i in range(1, n):
#         if idx[i + 1] < idx[i]:
#             res += 1

#     for _ in range(m):
#         l, r = gai()
#         nums[l - 1], nums[r - 1] = nums[r - 1], nums[l - 1]
#         idx[nums[l - 1]], idx[nums[r - 1]] = idx[nums[r - 1]], idx[nums[l - 1]]

#         if idx[nums[r]]

# # for _ in range(int(input())):
# test()
def GFG(n, m, values, swaps):
    values.insert(0, 0)
    res = []
    position = [0] * (n + 1)
    for i in range(1, n + 1):
        position[values[i]] = i
    count = 1
    for i in range(1, n):
        count += position[i] > position[i + 1]
    updated_pairs = set()
    for i in range(m):
        l, r = swaps[i]
        if values[l] + 1 <= n:
            updated_pairs.add((values[l], values[l] + 1))
        if values[l] - 1 >= 1:
            updated_pairs.add((values[l] - 1, values[l]))
        if values[r] + 1 <= n:
            updated_pairs.add((values[r], values[r] + 1))
        if values[r] - 1 >= 1:
            updated_pairs.add((values[r] - 1, values[r]))
        for swapped in updated_pairs:
            count -= position[swapped[0]] > position[swapped[1]]
        values[l], values[r] = values[r], values[l]
        position[values[l]] = l
        position[values[r]] = r
        for swapped in updated_pairs:
            count += position[swapped[0]] > position[swapped[1]]
        res.append(count)
        updated_pairs.clear()
    return res

if __name__ == "__main__":
    n, m = list(map(int, input().split()))
    values = list(map(int, input().split()))
    swaps = []
    for i in range(m):
        swaps.append(list(map(int, input().split())))
    res = GFG(n, m, values, swaps)
    for i in res:
        print(i)