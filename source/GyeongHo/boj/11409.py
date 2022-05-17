import sys
input = sys.stdin.readline
max_val = 2 ** 31

n = int(input())
dp = [[-1] * (n + 1) for _ in range(n + 1)]
arr = [[0] * 2 for _ in range(n + 1)]

for i in range(1, n + 1):
    arr[i][0], arr[i][1] = map(int, input().split())

def dfs(start, end):
    if (dp[start][end] != -1):
        return dp[start][end]
    if (start == end):
        return 0

    min_val = max_val
    for i in range(start, end):
        min_val = min(min_val, arr[start][0] * arr[i][1] * arr[end][1] + dfs(start, i) + dfs(i + 1, end))
    
    dp[start][end] = min_val
    return dp[start][end]

print(dfs(1, n))