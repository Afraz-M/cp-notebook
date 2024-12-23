import sys

print = lambda x: sys.stdout.write(str(x))
currBal = int(input())
numOps = int(input())
transactions = {}
tID = 1
history = [currBal]
res = []
for _ in range(numOps):
    operation = input().split()
    op = operation[0]
    if op == "read":
        res.append(currBal)
    elif op == "credit":
        amount = int(operation[1])
        currBal += amount
        transactions[tID] = -amount
        tID += 1
    elif op == "debit":
        amount = int(operation[1])
        currBal -= amount
        transactions[tID] = amount
        tID += 1
    elif op == "abort":
        idx = int(operation[1])
        if idx in transactions:
            currBal += transactions[idx]
    elif op == "rollback":
        idx = int(operation[1])
        if 0 <= idx < len(history):
            currBal = history[idx]
            transactions.clear()
    elif op == "commit":
        history.append(currBal)
        transactions.clear()
for i in res[:-1]:
    print(i)
    print("\n")
print(res[-1])
sys.exit()