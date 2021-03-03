n, m = map(int, input().split())
maze = [[False] * m for _ in range(n)]
for i in range(n):
    tmp = list(input())
    for j in range(m):
        if tmp[j] == '1':
            maze[i][j] = True

count = [[0] * m for _ in range(n)]
visited = [[False] * m for _ in range(n)]
dirX = [0, 0, -1, 1]
dirY = [1, -1, 0, 0]

def bfs(startY, startX):
    q = [(startY, startX)]
    visited[startY][startX] = True
    while q:
        posY, posX = q.pop(0)
        for i in range(4):
            newY = posY + dirY[i]
            newX = posX + dirX[i]
            if (newY >= 0 and newY < n and newX >= 0 and newX < m and not visited[newY][newX] and maze[newY][newX] and count[newY][newX] == 0):
                q.append((newY, newX))
                visited[newY][newX] = True
                count[newY][newX] = count[posY][posX] + 1

bfs(0, 0)
print(count[n - 1][m - 1] + 1)