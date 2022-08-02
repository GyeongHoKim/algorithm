import sys
input = sys.stdin.readline

def dfs(diag, isBlack, cnt):
    global black, white
    if diag >= 2 * n - 1:
        if isBlack:
            black = max(black, cnt)
        else:
            white = max(white, cnt)
        return
    for i in range(n):
        for j in range(n):
            if i + j != diag or board[i][j] == 0 or r[i - j + n - 1]:
                continue
            r[i - j + n - 1] = True
            dfs(diag + 2, isBlack, cnt + 1)
            r[i - j + n - 1] = False
    dfs(diag + 2, isBlack, cnt)

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
l = [False] * (2 * n - 1)
r = [False] * (2 * n - 1)
black, white = 0, 0

dfs(0, True, 0)
dfs(1, False, 0)
print(black + white)
