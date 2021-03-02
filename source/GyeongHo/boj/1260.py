import sys;
input = sys.stdin.readline

n, m, v = map(int, input().split())
graph = [[] for _ in range(n)]
visited1 = [False] * n
visited2 = [False] * n

for i in range(m):
	n1, n2 = map(int, input().split())
	graph[n1 - 1].append(n2 - 1)
	graph[n2 - 1].append(n1 - 1)

for i in range(n):
	graph[i].sort()

def dfs(graph, v, visited):
	visited[v] = True
	print(v + 1, end=' ')
	for i in graph[v]:
		if not visited[i]:
			dfs(graph, i, visited)

def bfs(graph, start, visited):
	q = [start]
	visited[start] = True
	while q:
		v = q.pop(0)
		print(v + 1, end=' ')
		for i in graph[v]:
			if not visited[i]:
				q.append(i)
				visited[i] = True

dfs(graph, v - 1, visited1)
print()
bfs(graph, v - 1, visited2)
