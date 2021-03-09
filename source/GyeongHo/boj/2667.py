n = int(input())
square = [list(map(int, input())) for _ in range(n)]
house = []
town = 0
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

def chk(i, j):
	if 0 <= i < n and 0 <= j < n and square[i][j] == 1:
		return True
	return False

def bfs(y, x, count):
	q = [(y, x)]
	square[y][x] = 0
	while q:
		posY, posX = q.pop(0)
		for i in range(4):
			newY = posY + dy[i]
			newX = posX + dx[i]
			if chk(newY, newX):
				q.append((newY, newX))
				square[newY][newX] = 0
				count += 1
	return count

for i in range(n):
	for j in range(n):
		if square[i][j] == 1:
			house.append(bfs(i, j, 1))
			town += 1

house.sort()
print(town)
for i in house:
	print(i)
