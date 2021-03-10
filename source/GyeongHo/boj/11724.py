n, m = map(int, input().split())
visited = [False] * n
component = 0
graph = [[] for _ in range(n)]
for i in range(m):
	start, end = map(int, input().split())
	graph[start - 1].append(end - 1)
	graph[end - 1].append(start - 1)

def dfs(v):
	visited[v] = True
	for i in graph[v]:
		if not visited[i]:
			dfs(i)

for i in range(n):
	if not visited[i]:
		dfs(i)
		component += 1

print(component)
