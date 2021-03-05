m, n = map(int, input().split())
warehouse = []
start = []
dirX = [0, 0, 1, -1]
dirY = [1, -1, 0, 0]
visited = [[False] * m for _ in range(n)]
count = [[0] * m for _ in range(n)]

for i in range(n):
	warehouse.append(list(map(int, input().split())))
	for j in range(m):
		if warehouse[i][j] == 1:
			start.append((i, j))

def checkInRange(i, j):
	if i < 0 or i >= n:
		return False
	if j < 0 or j >= m:
		return False
	return True

def bfs():
	for i, j in start:
		visited[i][j] = True
	while start:
		posY, posX = start.pop(0)
		for i in range(4):
			newY = posY + dirY[i]
			newX = posX + dirX[i]
			if checkInRange(newY, newX):
				if not visited[newY][newX] and warehouse[newY][newX] == 0:
					start.append((newY, newX))
					visited[newY][newX] = True
					count[newY][newX] = count[posY][posX] + 1

def checkImpossible():
	for i in range(n):
		for j in range(m):
			if not visited[i][j] and warehouse[i][j] != -1:
				return True
	return False

def  dayCount():
	MAX = 0
	for i in range(n):
		MAX = max(MAX, max(count[i]))
	return MAX

bfs()

if checkImpossible():
	print(-1)
else:
	print(dayCount())
