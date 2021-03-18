def illKnight(n, m):
	if n > 2:
		if m > 6:
			return m - 5 + 3
		elif m < 4:
			return m
		else:
			return 4
	elif n == 2:
		if m > 6:
			return 4
		else:
			return (m + 1) // 2
	else:
		return 1

n, m = map(int, input().split())
print(illKnight(n, m))
