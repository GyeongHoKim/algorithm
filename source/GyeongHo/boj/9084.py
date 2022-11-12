import sys
input = sys.stdin.readline

T = int(input())
while T > 0:
    n = int(input())
    arr = list(map(int, input().split()))
    money = int(input())
    dp = [0] * (money + 1)
    dp[0] = 1
    for i in range(n):
        for j in range(arr[i], money + 1):
            dp[j] = dp[j] + dp[j - arr[i]]
    print(dp[money])
    T -= 1