def solve():
    t = int(input())
    for _ in range(t):
        n, d, l = map(int, input().split())
        if l > n or d >= n or (l == n and d > 1):
            print(-1)
            continue
        if d == 1:
            if l == n:
                for i in range(2, n + 1):
                    print(1, i)
            else:
                print(-1)
            continue
        if d == 2:
            if l == n:
                for i in range(2, n + 1):
                    print(1, i)
            elif l == n - 1:
                for i in range(2, n + 1):
                    print(1, i)
            else:
                for i in range(2, l + 1):
                    print(1, i)
                for i in range(l + 1, n + 1):
                    print(1, i)
            continue
        tree = []
        for i in range(1, d + 1):
            tree.append((i, i + 1))
        remaining_leaves = l - 2
        if remaining_leaves < 0:
            print(-1)
            continue
        for _ in range(remaining_leaves):
            tree.append((2, d + 2))
            d += 1
        for edge in tree:
            print(edge[0], edge[1])

solve()
