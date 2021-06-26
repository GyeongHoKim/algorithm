import heapq
import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    minH = []
    maxH = []
    visited = [False] * 1000001
    k = int(input())
    for key in range(k):
        instruction, num = input().split()
        num = int(num)
        if instruction == 'I':
            heapq.heappush(minH, (num, key))
            heapq.heappush(maxH, (num * -1, key))
            visited[key] = True
        else:
            if num == 1:
                while maxH and not visited[maxH[0][1]]:
                    heapq.heappop(maxH)
                if maxH:
                    visited[maxH[0][1]] = False
                    heapq.heappop(maxH)
            else:
                while minH and not visited[minH[0][1]]:
                    heapq.heappop(minH)
                if minH:
                    visited[minH[0][1]] = False
                    heapq.heappop(minH)
    
    while minH and not visited[minH[0][1]]:
        heapq.heappop(minH)
    while maxH and not visited[maxH[0][1]]:
        heapq.heappop(maxH)

    if minH and maxH:
        print(maxH[0][0] * -1, minH[0][0])
    else:
        print("EMPTY")