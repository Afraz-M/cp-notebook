MOD = 998244353

def mod_exp(base, exp, mod):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def solve_bincatmod(t, queries):
    results = []
    for n in queries:
        result = 0
        length = 1
        current = 1
        
        while current <= n:
            # Range of numbers with binary length 'length'
            next_current = min(n + 1, 1 << length)
            count = next_current - current
            
            # Contribution of this range
            power = mod_exp(2, length, MOD)
            result = (result * mod_exp(power, count, MOD) + sum(range(current, next_current))) % MOD
            
            current = next_current
            length += 1
        
        results.append(result)
    return results

# Input Example
t = 2
queries = [3, 7]
results = solve_bincatmod(t, queries)
print("\n".join(map(str, results)))
