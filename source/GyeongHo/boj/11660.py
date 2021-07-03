import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if j:
            arr[i][j] += arr[i][j - 1]

for _ in range(m):
    y1, x1, y2, x2 = map(lambda x: int(x) - 1, input().split())
    ans = 0
    for i in range(y1, y2 + 1):
        if x1:
            ans -= arr[i][x1 - 1]
        ans += arr[i][x2]
    print(ans)