import sys
input = sys.stdin.readline

n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(n)]
isItDiff = [[False] * m for _ in range(n)]

for i in range(n):
	for j in range(m):
		if A[i][j] != B[i][j]:
			isItDiff[i][j] = True

def flip(y, x):
	for i in range(y, y + 3):
		for j in range(x, x + 3):
			A[i][j] = 1 - A[i][j]
			if isItDiff[i][j]:
				isItDiff[i][j] = False
			else:
				isItDiff[i][j] = True


def countFlip(ret):
	for i in range(n - 2):
		for j in range(m - 2):
			if isItDiff[i][j]:
				flip(i, j)
				ret += 1
			if j == m - 3:
				if isItDiff[i][j] or isItDiff[i][j - 1] or isItDiff[i][j - 2]:
					return -1
	for trueOrFalse in isItDiff:
		if True in trueOrFalse:
			return -1
	return ret

if n < 3 or m < 3:
	flag = True
	for trueOrFalse in isItDiff:
		if True in trueOrFalse:
			print(-1)
			flag = False
	if flag:
		print(0)
else:
	print(countFlip(0))
