import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
n = int(input())
board = [[0] * n for _ in range(n)]
apple = int(input())
for _ in range(apple):
    y, x = map(int, input().split())
    board[y - 1][x - 1] = 1
instr = int(input())
times = [0] * (n ** 2)
times[0] = 1
for _ in range(instr):
    time, dir = input().split()
    if dir == "D":
        times[int(time)] = 1
    else:
        times[int(time)] = -1

snake = deque([(0, 0)])

def inRange(y, x):
    if 0 <= y < n and 0 <= x < n:
        return True
    return False

def move(dir = 0):
    time = 0
    while True:
        dir = (dir + times[time]) % 4
        ny, nx = snake[-1][0] + dy[dir], snake[-1][1] + dx[dir]
        time += 1
        if not inRange(ny, nx) or (ny, nx) in snake:
            return time
        snake.append((ny, nx))
        if board[ny][nx] == 1:
            board[ny][nx] = 0
        else:
            snake.popleft()

print(move())