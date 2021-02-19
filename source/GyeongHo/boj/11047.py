n, k = map(int, input().split())
A = []
for i in range(n):
	A.append(int(input()))
i = n - 1
ret = 0
while k != 0:
	while A[i] > k:
		i -= 1
	ret += k // A[i]
	k = k % A[i]
print(ret)
