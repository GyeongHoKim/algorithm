# 0은 빈 칸, 1은 벽, 2는 놓을 수 있는 칸
from itertools import combinations
from collections import deque
import sys
input = sys.stdin.readline

def inRange(y, x):
    if 0 <= y < n and 0 <= x < n:
        return True
    return False

def bfs(case):
    dist = [[987654321] * n for _ in range(n)]
    q = deque(case)
    time = 0
    for y, x in case:
        dist[y][x] = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if not inRange(ny, nx) or lab[ny][nx] == 1 or dist[ny][nx] <= dist[y][x] + 1:
                continue
            dist[ny][nx] = dist[y][x] + 1
            q.append((ny, nx))
    for i in range(n):
        for j in range(n):
            if dist[i][j] == 987654321 and lab[i][j] != 1:
                return 987654321
            elif dist[i][j] != 987654321:
                time = max(time, dist[i][j])
    return time


n, m = map(int, input().split())
lab = [[0] * n for _ in range(n)]
possible = []
dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]
for i in range(n):
    tmp = list(map(int, input().split()))
    for j in range(n):
        lab[i][j] = tmp[j]
        if tmp[j] == 2:
            possible.append((i, j))

ans = 987654321
for case in list(combinations(possible, m)):
    ans = min(ans, bfs(case))
print(ans if ans != 987654321 else -1)