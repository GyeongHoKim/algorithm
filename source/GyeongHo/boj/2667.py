n = int(input())
MAP = [list(map(int, input())) for _ in range(n)]
visited = [[False] * n for _ in range(n)]
town = 0
house = []
dirY = [0, 0, 1, -1]
dirX = [1, -1, 0, 0]

def chk(i, j):
    if 0 <= i < n and 0 <= j < n and not visited[i][j] and MAP[i][j] == 1:
        return True
    return False

def bfs(i, j):
    q = [(i, j)]
    visited[i][j] = True
    MAX = 0
    print(q)
    while q:
        posY, posX = q.pop(0)
        for i in range(4):
            newY = posY + dirY[i]
            newX = posX + dirX[i]
            if chk(newY, newX):
                MAP[newY][newX] = MAP[posY][posX] + 1
                q.append((newY, newX))
                visited[newY][newX] = True
                MAX = max(MAX, MAP[newY][newX])
    return MAX

for i in range(n):
    for j in range(n):
        if MAP[i][j] == 1:
            house.append(bfs(i, j))
            town += 1

print(MAP)

house.sort()
print(town)
for i in house:
    print(i)