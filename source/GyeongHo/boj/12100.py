import copy

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
ans = 0

def up(board):
    for j in range(n):
        pos = 0
        for i in range(1, n):
            if board[i][j] == 0:
                continue
            tmp = board[i][j]
            board[i][j] = 0
            if board[pos][j] == 0:
                board[pos][j] = tmp
            elif board[pos][j] == tmp:
                board[pos][j] *= 2
                pos += 1
            else:
                pos += 1
                board[pos][j] = tmp
    return board
def down(board):
    for j in range(n):
        pos = n - 1
        for i in range(n - 2, -1, -1):
            if board[i][j] == 0:
                continue
            tmp = board[i][j]
            board[i][j] = 0
            if board[pos][j] == 0:
                board[pos][j] = tmp
            elif board[pos][j] == tmp:
                board[pos][j] *= 2
                pos -= 1
            else:
                pos -= 1
                board[pos][j] = tmp
    return board
def left(board):
    for i in range(n):
        pos = 0
        for j in range(1, n):
            if board[i][j] == 0:
                continue
            tmp = board[i][j]
            board[i][j] = 0
            if board[i][pos] == 0:
                board[i][pos] = tmp
            elif board[i][pos] == tmp:
                board[i][pos] *= 2
                pos += 1
            else:
                pos += 1
                board[i][pos] = tmp
    return board
def right(board):
    for i in range(n):
        pos = n - 1
        for j in range(n - 2, -1, -1):
            if board[i][j] == 0:
                continue
            tmp = board[i][j]
            board[i][j] = 0
            if board[i][pos] == 0:
                board[i][pos] = tmp
            elif board[i][pos] == tmp:
                board[i][pos] *= 2
                pos -= 1
            else:
                pos -= 1
                board[i][pos] = tmp
    return board

def dfs(depth, board):
    if depth >= 5:
        return max(map(max, board))
    return max(dfs(depth + 1, up(copy.deepcopy(board))), dfs(depth + 1, down(copy.deepcopy(board))), dfs(depth + 1, left(copy.deepcopy(board))), dfs(depth + 1, right(copy.deepcopy(board))))

print(dfs(0, board))
