def illKnight(n, m):
	if n == 2:
		if m > 6:
			return 3
		else:
			return m // 3
	elif n > 2:
		if m > 6:
			return m - 5
	else:
		return 0

n, m = map(int, input().split())
print(illKnight(n, m))
