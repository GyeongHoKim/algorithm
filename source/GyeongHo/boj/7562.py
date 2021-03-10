dy = (-2, -2, -1, -1, 1, 1, 2, 2)
dx = (-1, 1, -2, 2, -2, 2, -1, 1)

def bfs(i, j, chess, I):
	q = [(i, j)]
	chess[i][j] += 1
	while q:
		posY, posX = q.pop(0)
		for i in range(8):
			newY, newX = posY + dy[i], posX + dx[i]
			if 0 <= newY < I and 0 <= newX < I and chess[newY][newX] == 0:
				chess[newY][newX] = chess[posY][posX] + 1
				q.append((newY, newX))

T = int(input())
for _ in range(T):
	I = int(input())
	y, x = map(int, input().split())
	targetY, targetX = map(int, input().split())
	chess = [[0] * I for _ in range(I)]
	bfs(y, x, chess, I)
	print(chess[targetY][targetX] - 1)
