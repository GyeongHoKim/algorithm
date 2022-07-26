import sys
input = sys.stdin.readline
print = sys.stdout.write

triangle = "  *   * * *****"
db = [[' '] * 6500 for _ in range(3500)]

def star(i, j, n):
    if n == 1:
        idx = 0
        for y in range(i, i + 3):
            for x in range(j, j + 5):
                db[y][x] = triangle[idx]
                idx += 1
        return
    star(i, j + 3 * n // 2, n // 2)
    star(i + 3 * n // 2, j, n // 2)
    star(i + 3 * n // 2, j + 3 * n, n // 2)

n = int(input())
star(0, 0, n // 3)
for i in range(n):
    for j in range(n * 2):
        print(db[i][j])
    print('\n')