import sys
from collections import deque
input = sys.stdin.readline

def rotate_gear(idx, dir):
    if visited[idx]:
        return
    visited[idx] = True
    if idx > 0 and gears[idx][6] != gears[idx - 1][2]:
        rotate_gear(idx - 1, dir * -1)
    if idx < 3 and gears[idx][2] != gears[idx + 1][6]:
        rotate_gear(idx + 1, dir * -1)
    gears[idx].rotate(dir)

gears = [deque() for _ in range(4)]
for i in range(4):
    tmp = input().rstrip()
    for j in range(8):
        gears[i].append(int(tmp[j]))

for _ in range(int(input())):
    idx, dir = map(int, input().split())
    visited = [False] * 4
    rotate_gear(idx - 1, dir)

score = gears[0][0] + gears[1][0] * 2 + gears[2][0] * 4 + gears[3][0] * 8
print(score)