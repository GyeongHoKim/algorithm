import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
walls = [[0] * m for _ in range(n)]
for i in range(n):
    tmp = input().rstrip()
    for j in range(m):
        walls[i][j] = int(tmp[j])

dist = [[[987654321] * m for _ in range(n)] for _ in range(2)]
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

def bfs(start_y = 0, start_x = 0, start_flag = 0):
    q = deque()
    q.append((start_flag, start_y, start_x))
    dist[start_flag][start_y][start_x] = 1
    while (q):
        flag, y, x = q.popleft()
        if y == n - 1 and x == m - 1:
            return dist[flag][y][x]
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny < 0 or nx < 0 or ny >= n or nx >= m:
                continue
            if walls[ny][nx] == 1 and flag == 0:
                dist[1][ny][nx] = dist[flag][y][x] + 1
                q.append((1, ny, nx))
            elif walls[ny][nx] != 1 and dist[flag][ny][nx] > dist[flag][y][x] + 1:
                dist[flag][ny][nx] = dist[flag][y][x] + 1
                q.append((flag, ny, nx))
    return -1

print(bfs(0, 0, 0))