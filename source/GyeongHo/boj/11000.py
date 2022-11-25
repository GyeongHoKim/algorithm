import sys
import heapq
input = sys.stdin.readline

n = int(input())
lectures = [tuple(map(int, input().split())) for _ in range(n)]
lectures.sort(key=lambda x: x[0])
room = []
heapq.heappush(room, lectures[0][1])

for i in range(1, n):
    start, end = lectures[i]
    if room[0] <= start:
        heapq.heappop(room)
        heapq.heappush(room, end)
    else:
        heapq.heappush(room, end)
print(len(room))