import sys
input = sys.stdin.readline

red, blue, hole = (0, 0), (0, 0), (0, 0)
ans = 11
dy = [0, -1, 0, 1]
dx = [-1, 0, 1, 0]
n, m = map(int, input().split())
board = [[0] * m for _ in range(n)]


class node:
    def __init__(self, y, x):
        self.y = y
        self.x = x

    def __eq__(self, other):
        return self.y == other.y and self.x == other.x

    def __ne__(self, other):
        return self.y != other.y or self.x != other.x


for i in range(n):
    tmp = input()
    for j in range(m):
        if tmp[j] == 'R':
            red = node(i, j)
        elif tmp[j] == 'B':
            blue = node(i, j)
        elif tmp[j] == 'O':
            hole = node(i, j)
        elif tmp[j] == '#':
            board[i][j] = -1


def inRange(y, x):
    if 0 <= y < n and 0 <= x < m:
        return True
    return False


def move(red, blue, hole, dir):
    redCnt, blueCnt = 0, 0
    while inRange(red.y + dy[dir], red.x + dx[dir]) and board[red.y + dy[dir]][red.x + dx[dir]] != -1 and red != hole:
        red.y += dy[dir]
        red.x += dx[dir]
        redCnt += 1
    while inRange(blue.y + dy[dir], blue.x + dx[dir]) and board[blue.y + dy[dir]][blue.x + dx[dir]] != -1 and blue != hole:
        blue.y += dy[dir]
        blue.x += dx[dir]
        blueCnt += 1
    if red == blue and red != hole:
        if redCnt < blueCnt:
            blue.y -= dy[dir]
            blue.x -= dx[dir]
        else:
            red.y -= dy[dir]
            red.x -= dx[dir]


def countMove(red, blue, hole, cnt=0):
    global ans
    if blue == hole:
        return
    if red == hole:
        ans = min(cnt, ans)
        return
    if cnt > 10:
        return
    for i in range(4):
        tmp = (red.y, red.x, blue.y, blue.x)
        move(red, blue, hole, i)
        countMove(red, blue, hole, cnt + 1)
        red.y, red.x, blue.y, blue.x = tmp[0], tmp[1], tmp[2], tmp[3]

countMove(red, blue, hole)
if ans > 10:
    print(-1)
else:
    print(ans)
