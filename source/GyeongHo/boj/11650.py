n = int(input())
spot = [list(map(int, input().split())) for _ in range(n)]

spot.sort(key=lambda x: (x[0], x[1]))
for element in spot:
	print(element[0], element[1])
