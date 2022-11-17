n = int(input())

dp = [0] * (n + 1)
dp[0] = 1
for i in range(1, n + 1):
    if i & 1 == 1:
        dp[i] = 0
        continue
    dp[i] = dp[i - 2] * 3
    for j in range(i - 4, -1, -2):
        dp[i] += dp[j] * 2

print(dp[n])