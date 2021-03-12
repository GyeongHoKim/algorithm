import sys
input = sys.stdin.readline

n = int(input())
coordinate = list(map(int, input().split()))

for i in range(n):
	count = 0
	for j in range(n):
		if coordinate[i] > coordinate[j]:
			count += 1
	print(count, end=' ')
