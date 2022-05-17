dp = [[100001] * 100001 for _ in range(100001)]

n, k = map(int, input().split())
dp[1][k] = 0
for i in range(2, n + 1):
    if i % k == 0:
        dp[i][k] = i // k
    dp[i][k] = min(dp[i - 1][k] + 1, dp[i][k])
    print(dp[i][k])

print(dp[n][k])