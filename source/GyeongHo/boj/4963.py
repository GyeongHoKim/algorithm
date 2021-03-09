dy = (0, 0, 1, 1, 1, -1, -1, -1)
dx = (1, -1, 0, 1, -1, 0, 1, -1)

def chk(i, j, arr):
	if 0 <= i < h and 0 <= j < w and arr[i][j] == 1:
		return True
	return False

def bfs(y, x, arr):
	q = [(y, x)]
	arr[y][x] = 0
	while q:
		posY, posX = q.pop(0)
		for i in range(8):
			newY = posY + dy[i]
			newX = posX + dx[i]
			if chk(newY, newX, arr):
				q.append((newY, newX))
				arr[newY][newX] = 0

while True:
	w, h = map(int, input().split())
	if w == 0 and h == 0:
		break
	glob = [list(map(int, input().split())) for _ in range(h)]
	island = 0

	for i in range(h):
		for j in range(w):
			if glob[i][j] == 1:
				bfs(i, j, glob)
				island += 1

	print(island)
