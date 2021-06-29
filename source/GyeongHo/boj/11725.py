from collections import deque

n = int(input())
graph = [[] for _ in range(n + 1)]
depth = [-1] * (n + 1)
for _ in range(n - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
depth[1] = 0

q = deque([1])
while q:
    node = q.popleft()
    for linked in graph[node]:
        if depth[linked] != -1:
            continue
        depth[linked] = depth[node] + 1
        q.append(linked)

for child in range(2, n + 1):
    for parent in graph[child]:
        if depth[parent] < depth[child]:
            print(parent)
            break