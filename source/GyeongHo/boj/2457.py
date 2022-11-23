import sys
input = sys.stdin.readline

n = int(input())
dates = []
for _ in range(n):
    tmp = list(map(int, input().split()))
    dates.append((tmp[0] * 100 + tmp[1], tmp[2] * 100 + tmp[3]))
dates.sort()

ans = 0
lastStart = 0
lastEnd = 301
prevStart = 0
prevEnd = 0
while lastEnd <= 1130 and lastEnd != 0:
    for start, end in dates:
        if start <= lastEnd and end > lastEnd and end > prevEnd:
            prevStart = start
            prevEnd = end
    if prevEnd == lastEnd:
        lastEnd = 0
        break
    lastStart = prevStart
    lastEnd = prevEnd
    ans += 1

if lastEnd == 0:
    print(0)
else:
    print(ans)