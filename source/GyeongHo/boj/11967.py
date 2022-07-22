from collections import deque
import sys
input = sys.stdin.readline

def bfs(start_y = 1, start_x = 1):
    dy = [0, 0, 1, -1]
    dx = [1, -1, 0, 0]
    q = deque([(start_y, start_x)])
    light[start_y][start_x] = True
    visited[start_y][start_x] = True
    cnt = 1
    while q:
        cur_y, cur_x = q.popleft()
        for y, x in graph[cur_y][cur_x]:
            if light[y][x]:
                continue
            if tmp[y][x] and not visited[y][x]:
                q.append((y, x))
                visited[y][x] = True
            light[y][x] = True
            cnt += 1
        for i in range(4):
            ny, nx = cur_y + dy[i], cur_x + dx[i]
            if 0 < ny <= n and 0 < nx <= n and light[ny][nx] and not visited[ny][nx]:
                q.append((ny, nx))
                visited[ny][nx] = True
            if 0 < ny <= n and 0 < nx <= n and not light[ny][nx] and not visited[ny][nx]:
                tmp[ny][nx] = True
    return cnt
        

n, m = map(int, input().split())
graph = [[[] for _ in range(n + 1)] for _ in range(n + 1)]
light = [[False] * (n + 1) for _ in range(n + 1)]
visited = [[False] * (n + 1) for _ in range(n + 1)]
tmp = [[False] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    start_y, start_x, end_y, end_x = map(int, input().split())
    graph[start_y][start_x].append((end_y, end_x))

print(bfs())