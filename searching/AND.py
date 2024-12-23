def primes(N):
    pr = []
    lp = [0] * (N + 1)
    for i in range(2, N + 1):
        if lp[i] == 0:
            lp[i] = i
            pr.append(i)
        j = 0
        while j < len(pr) and i * pr[j] <= N:
            lp[i * pr[j]] = pr[j]
            if pr[j] == lp[i]:
                break
            j += 1
    return pr
n = 1000
print(len(primes(10**5)))