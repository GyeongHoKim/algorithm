import sys
from collections import deque
input = sys.stdin.readline

dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]

def bfs():
    finished = False
    while not finished:
        finished = True
        for turn in range(1, p + 1):
            if not players[turn]:
                continue
            finished = False
            q = players[turn]
            for _ in range(s[turn]):
                if not q:
                    break
                for _ in range(len(q)):
                    y, x = q.popleft()
                    for i in range(4):
                        ny, nx = y + dy[i], x + dx[i]
                        if 0 <= ny < n and 0 <= nx < m and board[ny][nx] == '.':
                            board[ny][nx] = str(turn)
                            q.append((ny,nx))
                            cnt[turn] += 1

n, m, p = map(int, input().split())
players = [deque() for _ in range(p + 1)]
s = [0] + list(map(int, input().split()))
board = [list(input().rstrip()) for _ in range(n)]
cnt = [0] * (p + 1)


for i in range(n):
    for j in range(m):
        if board[i][j] != '.' and board[i][j] != '#':
            cnt[int(board[i][j])] += 1
            players[int(board[i][j])].append((i,j))
        
bfs()
print(*cnt[1:])