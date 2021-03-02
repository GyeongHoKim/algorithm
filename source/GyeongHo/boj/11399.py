n = int(input())
timeList = list(map(int, input().split()))
timeList.sort()

result = 0
for i in range(n):
    result += timeList[i] * (n - i)

print(result)
