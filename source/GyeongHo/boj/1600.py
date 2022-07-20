import sys
from collections import deque
input = sys.stdin.readline

def inRange(ny, nx):
    if 0 <= ny < n and 0 <= nx < m:
        return True
    return False

def bfs(start_k = 0, start_y = 0, start_x = 0):
    q = deque([(start_k, start_y, start_x)])
    dist[start_k][start_y][start_x] = 0
    while q:
        cur_k, cur_y, cur_x = q.popleft()
        if cur_y == n - 1 and cur_x == m - 1:
            return dist[cur_k][cur_y][cur_x]
        for i in range(4):
            nk, ny, nx = cur_k, cur_y + dy[i], cur_x + dx[i]
            if not inRange(ny, nx) or zoo[ny][nx] == 1 or dist[nk][ny][nx] <= dist[cur_k][cur_y][cur_x] + 1:
                continue
            q.append((cur_k, ny, nx))
            dist[cur_k][ny][nx] = dist[cur_k][cur_y][cur_x] + 1
        
        if k <= cur_k:
            continue
        for i in range(8):
            nk, ny, nx = cur_k + 1, cur_y + kdy[i], cur_x + kdx[i]
            if not inRange(ny, nx) or zoo[ny][nx] == 1 or dist[nk][ny][nx] <= dist[cur_k][cur_y][cur_x] + 1:
                continue
            q.append((nk, ny, nx))
            dist[nk][ny][nx] = dist[cur_k][cur_y][cur_x] + 1
    return -1

k = int(input().rstrip())
m, n = map(int, input().split())
zoo = []
dist = [[[987654321] * m for _ in range(n)] for _ in range(k + 1)]
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
kdy = [2, 1, 2, 1, -1, -2, -1, -2]
kdx = [-1, -2, 1, 2, -2, -1, 2, 1]
for i in range(n):
    zoo.append(list(map(int, input().split())))

print(bfs())