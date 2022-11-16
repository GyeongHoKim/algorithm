import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coins = set()
for i in range(n):
    tmp = int(input())
    if tmp > 10000:
        n -= 1
        continue
    coins.add(tmp)

dp = [k + 1] * (k + 1)
dp[0] = 0

for coin in coins:
    for i in range(coin, k + 1):
        dp[i] = min(dp[i], dp[i - coin] + 1)
print(dp[k] if dp[k] < k + 1 else -1)