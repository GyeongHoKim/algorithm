import sys
import itertools
import copy
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
bitmasks = [(y, x) for x in range(m) for y in range(n)]
MAP = [[0] * m for _ in range(n)]
max_area = 0
startPoints = []

for i in range(n):
    tmp = list(map(int, input().split()))
    for j in range(m):
        if tmp[j] == 2:
            startPoints.append((i, j))
        MAP[i][j] = tmp[j]

def BFS(startPoints, wallIdx):
    global n, m, max_area, MAP
    copyMap = copy.deepcopy(MAP)
    for idx in wallIdx:
        y, x = idx
        if copyMap[y][x] != 0:
            return
        copyMap[y][x] = 1
    dy = [0, 0, -1, 1]
    dx = [1, -1, 0, 0]
    queue = deque()
    for startPoint in startPoints:
        queue.append(startPoint)
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny < 0 or ny >= n or nx < 0 or nx >= m or copyMap[ny][nx] != 0:
                continue
            copyMap[ny][nx] = 2
            queue.append((ny, nx))
    cnt = 0
    for i in range(n):
        for j in range(m):
            if copyMap[i][j] == 0:
                cnt += 1

    max_area = max(cnt, max_area)

for bitmask in list(itertools.combinations(bitmasks, 3)):
    BFS(startPoints, bitmask)

print(max_area)