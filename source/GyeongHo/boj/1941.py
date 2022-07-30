from itertools import combinations
from collections import deque

def bfs(q, visit):
    node_cnt = 0
    while q:
        y, x = q.popleft()
        node_cnt += 1
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny < 0 or ny >= 5 or nx < 0 or nx >= 5 or not visit[ny][nx]:
                continue
            q.append((ny, nx))
            visit[ny][nx] = False
    if node_cnt < 7:
        return False
    return True

seat = [input() for _ in range(5)]
selectNumber = [x for x in range(25)]
all = list(combinations(selectNumber, 7))
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
ans = 0

for case in all:
    s_cnt = 0
    visit = [[False] * 5 for _ in range(5)]
    firstNum = case[0]
    q = deque([(firstNum // 5, firstNum % 5)])
    for number in case:
        y = number // 5
        x = number % 5
        visit[y][x] = True
        if seat[y][x] == "S":
            s_cnt += 1
    if not s_cnt >= 4:
        continue
    visit[firstNum // 5][firstNum % 5] = False
    if bfs(q, visit):
        ans += 1
print(ans)