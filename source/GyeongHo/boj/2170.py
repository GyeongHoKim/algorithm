import sys
import heapq
input = sys.stdin.readline

n = int(input())
lines = [tuple(map(int, input().split())) for _ in range(n)]
lines.sort(key = lambda x : x[0])
prevStart = lines[0][0]
prevEnd = lines[0][1]
ans = 0

for i in range(1, n):
    start, end = lines[i]
    if start <= prevEnd:
        prevEnd = max(prevEnd, end)
    else:
        ans += prevEnd - prevStart
        prevStart = start
        prevEnd = end
ans += prevEnd - prevStart

print(ans)