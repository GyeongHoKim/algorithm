import sys
input = sys.stdin.readline

n = int(input())
timeList = [[0] * 2 for _ in range(100000)]
for i in range(n):
    timeList[i][0], timeList[i][1] = map(int, input().split())
timeList.sort(key = lambda x: (x[1], x[0]))

count = 1
endTime = timeList[0][1]
for i in range(1, n):
	if timeList[i][0] >= endTime:
		count += 1
		endTime = timeList[i][1]
print(count)
