from collections import deque
import sys
input = sys.stdin.readline

def bfs(q, visited):
    max_num = -1
    while q:
        cur = q.popleft()
        max_num = max(max_num, visited[cur])
        for i in range(20):
            nxt = cur ^ (1 << i)
            if nxt > n or visited[nxt] != -1:
                continue
            q.append(nxt)
            visited[nxt] = visited[cur] + 1
    return max_num

n = int(input())
m = int(input())
visited = [-1] * (n + 1)
q = deque()
for i in list(map(int, input().split())):
    visited[i] = 0
    q.append(i)

print(bfs(q, visited))