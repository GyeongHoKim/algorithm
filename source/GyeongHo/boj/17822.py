import sys
from collections import deque
input = sys.stdin.readline

n, m, t = map(int, input().split())
disks = [deque()]
for _ in range(n):
    disks.append(deque(list(map(int, input().split()))))

def summation():
    sum = 0
    num = 0
    for i in range(1, n + 1):
        for j in range(m):
            if disks[i][j] == 0:
                continue
            sum += disks[i][j]
            num += 1
    return (sum, num)
            

def simulate():
    flag = True
    chk = [[False] * m for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(m):
            if disks[i][j] == 0:
                continue
            if disks[i][j] == disks[i][j - 1]:
                chk[i][j], chk[i][j - 1] = True, True
                flag = False
            if i != 1 and disks[i][j] == disks[i - 1][j]:
                chk[i][j], chk[i - 1][j] = True, True
                flag = False
    for i in range(1, n + 1):
        for j in range(m):
            if chk[i][j]:
                disks[i][j] = 0
    if not flag:
        return
    sum, num = summation()
    if num == 0:
        return
    avg = sum / num
    for i in range(1, n + 1):
        for j in range(m):
            if disks[i][j] == 0:
                continue
            elif disks[i][j] > avg:
                disks[i][j] -= 1
            elif disks[i][j] < avg:
                disks[i][j] += 1
    return
    
for _ in range(t):
    x, d, k = map(int, input().split())
    for i in range(x, n + 1):
        if i % x != 0:
            continue
        disks[i].rotate(k * (-1 if d == 1 else 1))
    simulate()

print(summation()[0])
