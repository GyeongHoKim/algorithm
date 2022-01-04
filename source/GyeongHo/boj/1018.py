import sys
input = sys.stdin.readline

WB = [
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
]
BW = [
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
]

n, m = map(int, input().split())
board = [input().strip() for _ in range(n)]

def find(board, WB, BW):
    err = 64
    for i in range(n - 7):
        for j in range(m - 7):
            tmp1 = 0
            for y in range(8):
                for x in range(8):
                    if WB[y][x] != board[i + y][j + x]:
                        tmp1 += 1
            err = min(err, tmp1)
            tmp2 = 0
            for y in range(8):
                for x in range(8):
                    if tmp1 <= tmp2:
                        break
                    if BW[y][x] != board[i + y][j + x]:
                        tmp2 += 1
            err = min(err, tmp2)
    return err

print(find(board, WB, BW))