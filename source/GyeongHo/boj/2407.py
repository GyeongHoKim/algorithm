n, m = map(int, input().split())

arr = [[0] * 101 for _ in range(102)]
for i in range(1, 101):
    for j in range(101):
        if i == j or j == 0:
            arr[i][j] = 1

for i in range(1, n + 1):
    for j in range(m + 1):
        if i < j or arr[i][j] > 0:
            continue
        arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]

print(arr[n][m])