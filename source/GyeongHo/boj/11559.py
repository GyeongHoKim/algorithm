from collections import deque

dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]
board = [['.'] * 6 for _ in range(12)]
for i in range(12):
    tmp = input()
    for j in range(6):
        board[i][j] = tmp[j]

def inRange(y, x):
    if 0 <= y < 12 and 0 <= x < 6:
        return True
    return False

def bfs(start_y, start_x, color, visited):
    q = deque([(start_y, start_x)])
    visited[start_y][start_x] = True
    cnt = 0
    while q:
        y, x = q.popleft()
        cnt += 1
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if not inRange(ny, nx) or board[ny][nx] != color or visited[ny][nx]:
                continue
            q.append((ny, nx))
            visited[ny][nx] = True
    return cnt

def explode(visited):
    for i in range(12):
        for j in range(6):
            if visited[i][j] and board[i][j] != '.':
                board[i][j] = '.'

def traversal():
    flag = False
    for i in range(12):
        for j in range(6):
            if board[i][j] == '.':
                continue
            visited = [[False] * 6 for _ in range(12)]
            if bfs(i, j, board[i][j], visited) >= 4:
                flag = True
                explode(visited)
    return flag

def gravity():
    for j in range(6):
        pos = 11
        for i in range(11, -1, -1):
            if board[i][j] == '.':
                pos = i
                break
        else:
            continue
        tmp = pos
        for i in range(pos, -1, -1):
            if board[i][j] != '.':
                board[tmp][j] = board[i][j]
                board[i][j] = '.'
                tmp -= 1

ans = 0
while traversal():
    ans += 1
    gravity()

print(ans)