import sys
input = sys.stdin.readline

white = 0
blue = 0
n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]

def BahnGalJook(y, x, length):
    global white, blue
    compare = paper[y][x]

    for i in range(y, y + length):
        for j in range(x, x + length):
            if compare != paper[i][j]:
                new_length = length // 2
                BahnGalJook(y, x, new_length)
                BahnGalJook(y, x + new_length, new_length)
                BahnGalJook(y + new_length, x, new_length)
                BahnGalJook(y + new_length, x + new_length, new_length)
                return
    
    if compare == 0:
        white += 1
        return
    else:
        blue += 1
        return

BahnGalJook(0, 0, n)
print(white)
print(blue)