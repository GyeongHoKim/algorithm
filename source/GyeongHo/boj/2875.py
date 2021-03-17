def timsko(m, n, k):
	if m % 2 == 1:
		k -= 1
		m -= 1
	while k > 0:
		if m // 2 > n:
			m -= 2
			k -= 2
		elif n > m // 2:
			n -= 1
			k -= 1
		else:
			m -= 2
			n -= 1
			k -= 3
	return min(n, m // 2)

m, n, k = map(int, input().split())
print(timsko(m, n, k))
