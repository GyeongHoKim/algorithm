import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
cache = [[-1] * m for _ in range(n)]
visited = [[False] * m for _ in range(n)]
cache[n - 1][m - 1] = 1
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]

def inRange(y, x):
    if 0 <= y < n and 0 <= x < m:
        return True
    return False

def dfs(y, x):
    if y == n - 1 and x == m - 1:
        return 1
    if cache[y][x] != -1:
        return cache[y][x]
    
    total = 0
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if not inRange(ny, nx) or arr[y][x] <= arr[ny][nx] or visited[ny][nx]:
            continue
        visited[ny][nx] = True
        total += dfs(ny, nx)
        visited[ny][nx] = False
    cache[y][x] = max(cache[y][x], total)
    return total

ans = dfs(0, 0)
print(ans if ans != -1 else 0)