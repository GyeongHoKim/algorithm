import sys
input = sys.stdin.readline
print = sys.stdout.write

class Dice:
    def __init__(self, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0) -> None:
        self.a, self.b, self.c, self.d, self.e, self.f = a, b, c, d, e, f
    def move(self, dir, y, x, board) -> int:
        if dir == 1:
            tmp = self.c
            self.a, self.b, self.c, self.d, self.e = self.d, self.b, self.a, self.f, self.e
            if board[y][x] == 0:
                self.f = tmp
                board[y][x] = tmp
            else:
                self.f = board[y][x]
                board[y][x] = 0
        if dir == 2:
            tmp = self.d
            self.a, self.b, self.c, self.d, self.e = self.c, self.b, self.f, self.a, self.e
            if board[y][x] == 0:
                self.f = tmp
                board[y][x] = tmp
            else:
                self.f = board[y][x]
                board[y][x] = 0
        if dir == 3:
            tmp = self.e
            self.a, self.b, self.c, self.d, self.e = self.b, self.f, self.c, self.d, self.a
            if board[y][x] == 0:
                self.f = tmp
                board[y][x] = tmp
            else:
                self.f = board[y][x]
                board[y][x] = 0
        if dir == 4:
            tmp = self.b
            self.a, self.b, self.c, self.d, self.e = self.e, self.a, self.c, self.d, self.f
            if board[y][x] == 0:
                self.f = tmp
                board[y][x] = tmp
            else:
                self.f = board[y][x]
                board[y][x] = 0
        return self.a

dice = Dice()
n, m, y, x, _ = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
instrs = list(map(int, input().split()))
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

for instr in instrs:
    y, x = y + dy[instr - 1], x + dx[instr - 1]
    if 0 <= y < n and 0 <= x < m:
        print(str(dice.move(instr, y, x, board)) + "\n")
    else:
        y, x = y - dy[instr - 1], x - dx[instr - 1]