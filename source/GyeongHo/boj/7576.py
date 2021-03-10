import sys
input = sys.stdin.readline

m, n = map(int, input().split())
tomato = [list(map(int, input().split())) for _ in range(n)]
dy = (0, 0, 1, -1)
dx = (1, -1, 0, 0)

def bfs(q):
	MAX = -1
	while q:
		posY, posX = q.pop(0)
		for i in range(4):
			newY, newX = posY + dy[i], posX + dx[i]
			if 0 <= newY < n and 0 <= newX < m and tomato[newY][newX] == 0:
				tomato[newY][newX] = tomato[posY][posX] + 1
				q.append((newY, newX))
				MAX = max(MAX, tomato[newY][newX])
	for tot in tomato:
		if 0 in tot:
			return -1
	return MAX - 1

queue = []
for i in range(n):
	for j in range(m):
		if tomato[i][j] == 1:
			queue.append((i, j))

print(bfs(queue))
