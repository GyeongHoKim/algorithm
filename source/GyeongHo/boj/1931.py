n = int(input())
timeList = []
for i in range(n):
	a, b = map(int, input().split())
	timeList.append((a, b))

timeList.sort()

def solution(nextIdx, prevIdx, count):
	while nextIdx < n:
		if timeList[nextIdx][0] < timeList[prevIdx][1]:
			nextIdx += 1
		else:
			prevIdx = nextIdx
			nextIdx += 1
			count += 1
	return count

countList = [0] * n
for i in range(n):
	countList[i] = solution(i + 1, i, 1)
print(max(countList))
