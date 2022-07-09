import sys
from collections import deque
input = sys.stdin.readline

f, s, g, u, d = map(int, input().split())
dist = [f + 1] * (f + 1)

def bfs(start):
    q = deque([start])
    dist[start] = 0
    while q:
        cur = q.popleft()
        if cur == g:
            return dist[cur]
        for nxt in [cur + u, cur - d]:
            if nxt < 1 or nxt > f or dist[nxt] <= dist[cur] + 1:
                continue
            dist[nxt] = dist[cur] + 1
            q.append(nxt)
    return -1

result = bfs(s)
if result != -1:
    print(result)
else:
    print("use the stairs")