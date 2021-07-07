import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

n = int(input())
m = int(input())
cost = [INF] * (n + 1)
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    start, end, bus = map(int, input().split())
    graph[start].append((end, bus))

start, end = map(int, input().split())

def dijkstra(start, end):
    q = []
    heapq.heappush(q, (0, start))
    cost[start] = 0
    while q:
        dist, cur = heapq.heappop(q)
        if end == cur:
            return dist
        if cost[cur] < dist:
            continue
        for node in graph[cur]:
            bus = dist + node[1]
            if bus < cost[node[0]]:
                cost[node[0]] = bus
                heapq.heappush(q, (bus, node[0]))
    return cost[end]

print(dijkstra(start, end))