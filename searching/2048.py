tiles = [4]
current_tile_value = 8
while tiles[-1] <= 5 * 10 ** 6:
    next_tile_value = current_tile_value + tiles[-1] * 2
    tiles.append(next_tile_value)
    current_tile_value *= 2

modulus = 998244353

num_cases = int(input())
queries = list(map(int, input().split()))

max_value = max(queries)

result = [0] * (max_value + 1)
result[0] = 1

for i in range(len(tiles) - 1, -1, -1):
    for j in range(1, max_value + 1):
        if j - tiles[i] >= 0:
            result[j] = (result[j] + result[j - tiles[i]]) % modulus

for query in queries:
    print(result[query])
