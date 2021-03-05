import sys
input = sys.stdin.readline

m, n = map(int, input().split())
tomato = [list(map(int, input().split())) for _ in range(n)]
q = []
dirY = [0, 0, 1, -1]
dirX = [1, -1, 0, 0]

for i in range(n):
	for j in range(m):
		if tomato[i][j] == 1:
			q.append((i, j))

def countDay():
	maxDay = 0
	for row in tomato:
		if 0 in row:
			return -1
		maxDay = max(maxDay, max(row))
		return maxDay - 1

def chkCanGo(i, j):
	if 0 <= i < n and 0 <= j < m and tomato[i][j] == 0:
		return True
	return False

def bfs():
	while q:
		posY, posX = q.pop()
		for i in range(4):
			newY = posY + dirY[i]
			newX = posX + dirX[i]
			if chkCanGo(newY, newX):
				tomato[newY][newX] = tomato[posY][posX] + 1
				q.append((newY, newX))

bfs()
print(tomato)

print(countDay())
