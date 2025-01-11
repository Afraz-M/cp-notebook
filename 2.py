# def knapsack(values, weights, capacity):
#     n = len(values)
#     dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

#     for i in range(1, n + 1):
#         for w in range(1, capacity + 1):
#             if weights[i - 1] <= w:  
#                 dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
#             else:
#                 dp[i][w] = dp[i - 1][w]

#     return dp[n][capacity]

def knapsack(values, weights, capacity, items, contradictory_pairs):
    n = len(values)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    # Map item names to their indices
    item_to_index = {item: idx for idx, item in enumerate(items)}

    # Convert contradictory pairs to indices
    conflicts = {i: set() for i in range(n)}
    for item1, item2 in contradictory_pairs:
        idx1, idx2 = item_to_index[item1], item_to_index[item2]
        conflicts[idx1].add(idx2)
        conflicts[idx2].add(idx1)

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                include_value = values[i - 1] + dp[i - 1][w - weights[i - 1]]
                violates_contradiction = False
                for conflicting_item in conflicts[i - 1]:
                    if conflicting_item < i - 1 and dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]:
                        violates_contradiction = True
                        break

                if not violates_contradiction:
                    dp[i][w] = max(dp[i - 1][w], include_value)
                else:
                    dp[i][w] = dp[i - 1][w]
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][capacity]

def weight(word):
    weight = 0
    for i in word:
        weight += (ord(i) - 96)
    return weight

n, m = list(map(int, input().strip().split()))
words = input().split()
items = words.copy()
weights = list(map(int, input().strip().split()))
cont = []
for i in range(m):
    temp = input().split()
    cont.append(tuple(temp))
cap = int(input())
for i in range(n):
    words[i] = weight(words[i])

print(knapsack(words, weights, cap, items, cont))
