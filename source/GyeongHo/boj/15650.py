import sys

def pickM(arr, cnt, prev, n, m):
    if cnt >= m:
        for i in range(m):
            print(arr[i], end=' ')
        print()
        return
    for i in range(prev, n + 1):
        if visited[i]:
            continue
        arr[cnt] = i
        visited[i] = 1
        pickM(arr, cnt + 1, i, n, m)
        visited[i] = 0

n, m = map(int, sys.stdin.readline().split())
arr = [0] * n
visited = [0] * (n + 1)
pickM(arr, 0, 1, n, m)