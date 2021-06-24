import sys
input = sys.stdin.readline

n = int(input())
coordinate = list(map(int, input().split()))

coordinateDict = set(coordinate)
fuck = sorted(list(coordinateDict))
fucking = {fuck[i] : i for i in range(len(fuck))}
for c in coordinate:
	print(fucking[c], end=' ')