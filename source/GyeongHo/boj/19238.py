import sys
from collections import deque
from heapq import heappop, heappush
input = sys.stdin.readline

n, m, f = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
INF = int(1e9)
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]
taxi = list(map(int, input().split()))
srcs = [[] for _ in range(m)]
dsts = [[] for _ in range(m)]

for i in range(m):
    sy, sx, ey, ex = map(int, input().split())
    srcs[i] = [sy, sx]
    dsts[i] = [ey, ex]

picked = [False] * m

def inRange(y, x):
    if 0 <= y < n and 0 <= x < n:
        return True
    return False

def bfs():
    sy, sx = taxi[0] - 1, taxi[1] - 1
    dist = [[INF] * n for _ in range(n)]
    q = deque([(sy, sx)])
    dist[sy][sx] = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if not inRange(ny, nx) or dist[ny][nx] <= dist[y][x] + 1 or arr[ny][nx] == 1:
                continue
            q.append((ny, nx))
            dist[ny][nx] = dist[y][x] + 1
    return dist

def find_guest():
    global f
    dist = bfs()
    hq = []

    for i in range(m):
        y, x  = srcs[i][0] - 1, srcs[i][1] - 1
        if picked[i] or f - dist[y][x] < 0:
            continue
        heappush(hq, (dist[y][x], y, x, i))
    
    if not hq:
        return -1
    distance, _, _, idx = heappop(hq)
    f -= distance
    picked[idx] = True

    return idx

def go_dst(idx):
    global f
    dist = bfs()
    y, x = dsts[idx][0] - 1, dsts[idx][1] - 1
    if f - dist[y][x] < 0:
        return -1
    return dist[y][x]

cnt = m
while cnt > 0:
    idx = find_guest()
    if idx == -1:
        f = -1
        break
    taxi = srcs[idx]
    dist = go_dst(idx)
    if dist == -1:
        f = -1
        break
    f += dist
    taxi = dsts[idx]
    cnt -= 1

print(f)