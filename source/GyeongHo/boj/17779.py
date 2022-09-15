import sys
input = sys.stdin.readline

ans = 987654321
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
allCase = [(y, x, d1, d2) for y in range(n) for x in range(n) for d1 in range(1, n + 1) for d2 in range(1, n + 1)]

def chk(case):
    y, x, d1, d2 = case
    if d1 > 0 and d2 > 0 and 0 <= x < n and 0 <= y < n and x + d1 + d2 < n and y + d2 < n and y - d1 >= 0:
        return True
    return False

def areaFive(y, x, case):
    y1, x1, d1, d2 = case
    if y >= -x + y1 + x1 and y <= x + y1 - x1 and y <= -x + y1 + x1 + 2 * d2 and y >= x + y1 - x1 -  2 * d1:
        return True
    return False
    

def simulation(case):
    y1, x1, d1, d2 = case
    arr = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if areaFive(i, j, case):
                arr[i][j] = 5
            elif 0 <= j <= x1 + d1 and 0 <= i < y1:
                arr[i][j] = 1
            elif x1 + d1 < j < n and 0 <= i <= y1 - (d1 - d2):
                arr[i][j] = 2
            elif 0 <= j < x1 + d2 and y1 <= i < n:
                arr[i][j] = 3
            elif x1 + d2 <= j < n and y1 - d1 + d2 < i < n:
                arr[i][j] = 4
    return arr

for case in allCase:
    if not chk(case):
        continue
    gerrymandering = simulation(case)
    sum = [0] * 5
    for i in range(n):
        for j in range(n):
            sum[gerrymandering[i][j] - 1] += A[i][j]
    if 0 in sum:
        continue

    # print()
    # print(*case)
    # for i in range(n):
    #     print(*gerrymandering[i])
    # print("sum:",*sum)

    ans = min(max(sum) - min(sum), ans)

print(ans)