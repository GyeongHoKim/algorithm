from collections import deque

dist = [987654321] * 100001

def bfs(start, end):
    q = deque([start])
    dist[start] = 0
    while q:
        cur = q.popleft()
        if cur == end:
            return dist[end]
        for nxt in [cur - 1, cur + 1, cur * 2]:
            if nxt < 0 or nxt > 100000 or nxt > (k * 2 if n < k else n * 2):
                continue
            if nxt == cur * 2 and dist[cur] < dist[nxt]:
                q.appendleft(nxt)
                dist[nxt] = dist[cur]
            if nxt != cur * 2 and dist[cur] + 1 < dist[nxt]:
                q.append(nxt)
                dist[nxt] = dist[cur] + 1
    return -1

n, k = map(int, input().split())
print(bfs(n, k))
