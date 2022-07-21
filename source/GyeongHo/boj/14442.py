import sys
from collections import deque
input = sys.stdin.readline

def inRange(y, x):
    if 0 <= y < n and 0 <= x < m:
        return True
    return False

def bfs(start_k = 0, start_y = 0, start_x = 0):
    q = deque([(start_k, start_y, start_x)])
    dist[start_k][start_y][start_x] = 1
    while q:
        cur_k, cur_y, cur_x = q.popleft()
        if cur_y == n - 1 and cur_x == m - 1:
            return dist[cur_k][cur_y][cur_x]
        for i in range(4):
            nk, ny, nx = cur_k + 1, cur_y + dy[i], cur_x + dx[i]
            if inRange(ny, nx) and walls[ny][nx] == 0 and dist[cur_k][ny][nx] > dist[cur_k][cur_y][cur_x] + 1:
                q.append((cur_k, ny, nx))
                dist[cur_k][ny][nx] = dist[cur_k][cur_y][cur_x] + 1
            if inRange(ny, nx) and cur_k < k and walls[ny][nx] == 1 and dist[nk][ny][nx] > dist[cur_k][cur_y][cur_x] + 1:
                q.append((nk, ny, nx))
                dist[nk][ny][nx] = dist[cur_k][cur_y][cur_x] + 1
    return -1

dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
n, m, k = map(int, input().split())
walls = [[0] * m for _ in range(n)]
dist = [[[987654321] * m for _ in range(n)] for _ in range(k)]

for i in range(n):
    tmp = input().rstrip()
    for j in range(m):
        walls[i][j] = int(tmp[j])

print(bfs())