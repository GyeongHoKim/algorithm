from collections import deque

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if visited[i]:
                continue
            queue.append(i)
            visited[i] = True
    return visited

def solution(n, computers):
    network = 0
    graph = [[] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            if computers[i][j] == 1:
                graph[i].append(j)
    
    visited = [False] * n
    idx = 0
    for i in range(n):
        if visited[i]:
            continue
        visited = bfs(graph, i, visited)
        network += 1
        idx += 1
    return network