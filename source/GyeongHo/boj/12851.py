from collections import deque

def bfs(start):
    q = deque([start])
    dist[start][0] = 0
    dist[start][1] += 1
    while q:
        cur = q.popleft()
        for nxt in [cur - 1, cur + 1, cur * 2]:
            if nxt < 0 or nxt > (k * 2 if n <= k else n * 2) or nxt > 100000:
                continue
            if dist[nxt][0] != -1 and dist[nxt][0] < dist[cur][0] + 1:
                continue
            dist[nxt][0] = dist[cur][0] + 1
            dist[nxt][1] += 1
            q.append(nxt)

n, k = map(int, input().split())
dist = [[-1, 0] for _ in range(100001)]

bfs(n)
print(dist[k][0])
print(dist[k][1])