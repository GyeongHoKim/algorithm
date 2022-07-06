import sys
import copy
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
sea = [[0] * m for _ in range(n)]
for i in range(n):
    line = list(map(int, input().split()))
    for j in range(m):
        sea[i][j] = line[j]

def melting():
    yearLater = copy.deepcopy(sea)
    for i in range(n):
        for j in range(m):
            if sea[i][j] > 0:
                for k in range(4):
                    ny, nx = i + dy[k], j + dx[k]
                    if ny < 0 or ny >= n or nx < 0 or nx >= m:
                        continue
                    if sea[ny][nx] == 0 and yearLater[i][j] > 0:
                        yearLater[i][j] -= 1
    return yearLater

def bfs(start_y, start_x):
    q = deque([(start_y, start_x)])
    visited[start_y][start_x] = True
    while(q):
        cur_y, cur_x = q.popleft()
        for i in range(4):
            ny, nx = cur_y + dy[i], cur_x + dx[i]
            if ny < 0 or ny >= n or nx < 0 or nx >= m or sea[ny][nx] <= 0 or visited[ny][nx]:
                continue
            q.append((ny, nx))
            visited[ny][nx] = True
    return 1

cnt_year = 0
iceBerg = 1
while (iceBerg == 1):
    iceBerg = 0
    visited = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if sea[i][j] > 0 and not visited[i][j]:
                iceBerg += bfs(i, j)
    cnt_year += 1
    sea = melting()

if iceBerg == 0:
    print(0)
else:
    print(cnt_year - 1)