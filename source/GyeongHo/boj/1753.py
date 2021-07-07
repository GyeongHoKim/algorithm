import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

V, E = map(int, input().split())
start = int(input())
graph = [[] for i in range(V + 1)]
distance = [INF] * (V + 1)

for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist , cur = heapq.heappop(q)
        if distance[cur] < dist:
            continue
        for node in graph[cur]:
            cost = dist + node[1]
            if cost < distance[node[0]]:
                distance[node[0]] = cost
                heapq.heappush(q, (cost, node[0]))

dijkstra(start)

for i in range(1, V + 1):
    if distance[i] < INF:
        print(distance[i])
    else:
        print("INF")