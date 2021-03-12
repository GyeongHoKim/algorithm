count = 0
def dfs(n, i, j, arr):
	global count
	if n <= 1:
		for y in range(i, i + 2):
			for x in range(j, j + 2):
				arr[y][x] = count
				count += 1
		for i in arr:
			print(i)
		print()
		return
	dfs(n - 1, i, j, arr)
	dfs(n - 1, i, j + 2 ** (n - 1), arr)
	dfs(n - 1, i + 2 ** (n - 1), j, arr)
	dfs(n - 1, i + 2 ** (n - 1), j + 2 ** (n - 1), arr)

n, r, c = map(int, input().split())
arr = [[0] * (2 ** n) for _ in range(2 ** n)]
dfs(n, 0, 0, arr)
print(arr[r][c])
