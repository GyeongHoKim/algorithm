from collections import deque
import sys
input = sys.stdin.readline

def inRange(y, x):
    if 0 <= y < n and 0 <= x < m:
        return True
    return False

def set_time():
    q = deque()
    max_time = 0
    for i in range(n):
        for j in range(m):
            if lake[i][j] == 0:
                q.append((i, j))
                time[i][j] = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if not inRange(ny, nx) or time[ny][nx] <= time[y][x] + 1 or lake[ny][nx] == 0:
                continue
            q.append((ny, nx))
            time[ny][nx] = time[y][x] + 1
            max_time = time[ny][nx]
    return max_time

def bfs(day):
    start_y, start_x, end_y, end_x = swan[0][0], swan[0][1], swan[1][0], swan[1][1]
    visited = [[False] * m for _ in range(n)]
    q = deque([(start_y, start_x)])
    visited[start_y][start_x] = True
    while q:
        y, x = q.popleft()
        if y == end_y and x == end_x:
            return True
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if not inRange(ny, nx) or visited[ny][nx] or time[ny][nx] > day:
                continue
            q.append((ny, nx))
            visited[ny][nx] = True
    return False


n, m = map(int, input().split())
swan = []
lake = [[0] * m for _ in range(n)]
time = [[987654321] * m for _ in range(n)]
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
for i in range(n):
    tmp = input().rstrip()
    for j in range(m):
        if tmp[j] == 'L':
            swan.append((i, j))
        if tmp[j] == 'X':
            lake[i][j] = 1

min_time = 0
max_time = set_time()
days = max_time

while min_time <= max_time:
    mid = (min_time + max_time) // 2
    if bfs(mid):
        days = mid
        max_time = mid - 1
    else:
        min_time = mid + 1
print(days)