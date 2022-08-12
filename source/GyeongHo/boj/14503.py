import sys
input = sys.stdin.readline

n, m = map(int, input().split())
y, x, dir = map(int, input().split())
if dir == 3:
    dir = 1
elif dir == 1:
    dir = 3
place = [list(map(int, input().split())) for _ in range(n)]

cleaned = 0
visited = [[False] * m for _ in range(n)]
dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]

def inRange(y, x):
    if 0 <= y < n and 0 <= x < m:
        return True
    return False

def dfs(y, x, dir):
    global cleaned
    i = dir
    for _ in range(4):
        i = (i + 1) % 4
        ny, nx = y + dy[i], x + dx[i]
        if place[ny][nx] != 1 and not visited[ny][nx]:
            cleaned += 1
            visited[ny][nx] = True
            dfs(ny, nx, i)
    i = (dir + 2) % 4
    ny, nx = y + dy[i], x + dx[i]
    if place[ny][nx] == 1:
        print(cleaned)
        exit(0)
    else:
        dfs(ny, nx, dir)

visited[y][x] = True
cleaned += 1
dfs(y, x, dir)