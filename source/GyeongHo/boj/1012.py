import sys
from collections import deque
input = sys.stdin.readline

dy = (0, 0, 1, -1)
dx = (1, -1, 0, 0)
T = int(input())

def bfs(i, j, garden):
    q = deque([(i, j)])
    garden[i][j] = 0
    while q:
        posY, posX = q.popleft()
        for i in range(4):
            newY, newX = posY + dy[i], posX + dx[i]
            if 0 <= newY < n and 0 <= newX < m and garden[newY][newX] == 1:
                q.append((newY, newX))
                garden[newY][newX] = 0

for _ in range(T):
    n, m, k = map(int, input().split())
    garden = [[0] * m for _ in range(n)]
    count = 0

    for _ in range(k):
        i, j = map(int, input().split())
        garden[i][j] = 1

    for i in range(n):
        for j in range(m):
            if garden[i][j] == 1:
                count += 1
                bfs(i, j, garden)

    print(count)