def illKnight(n, m):
	if n == 2:
		if m > 6:
			return 3
		else:
			return m // 3
	elif n > 2:
		if m > 6:
			return m - 5 + 3
	else:
		return 1

n, m = map(int, input().split())
print(illKnight(n, m))
