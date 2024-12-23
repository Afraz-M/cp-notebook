from heapq import heappush, heappop

def medianSlidingWindow(nums, k: int):
    medians = []
    outgoing_num = {}
    small_list = []
    large_list = []

    for i in range(k):
        heappush(small_list, -nums[i])

    for i in range(k // 2):
        element = heappop(small_list)
        heappush(large_list, -element)

    balance = 0
    i = k
    while True:
        medians.append(float(-small_list[0]))

        if i >= len(nums):
            break

        out_num = nums[i - k]
        in_num = nums[i]
        i += 1

        if out_num <= -small_list[0]:
            balance -= 1
        else:
            balance += 1

        outgoing_num[out_num] = outgoing_num.get(out_num, 0) + 1

        if in_num <= -small_list[0]:
            balance += 1
            heappush(small_list, -in_num)
        else:
            balance -= 1
            heappush(large_list, in_num)

        if balance < 0:
            heappush(small_list, -heappop(large_list))
        elif balance > 0:
            heappush(large_list, -heappop(small_list))

        balance = 0

        while small_list and -small_list[0] in outgoing_num and outgoing_num[-small_list[0]] > 0:
            outgoing_num[-small_list[0]] -= 1
            heappop(small_list)

        while large_list and large_list[0] in outgoing_num and outgoing_num[large_list[0]] > 0:
            outgoing_num[large_list[0]] -= 1
            heappop(large_list)

    return medians

n, k = list(map(int, input().split()))
nums = list(map(int, input().split()))

print(" ".join([str(int(ele)) for ele in medianSlidingWindow(nums, k)]))
