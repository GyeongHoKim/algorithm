from collections import deque

def bfs(start):
    q = deque([start])
    dist[start] = 0
    pre[start] = start
    while q:
        cur = q.popleft()
        if cur == k:
            return dist[cur]
        for nxt in [cur - 1, cur + 1, cur * 2]:
            if nxt < 0 or nxt > 100000 or nxt > (k * 2 if n <= k else n * 2) or dist[nxt] <= dist[cur] + 1:
                continue
            q.append(nxt)
            dist[nxt] = dist[cur] + 1
            pre[nxt] = cur
    return -1

def route(end):
    arr = []
    cur = end
    while cur != pre[cur]:
        arr.append(cur)
        cur = pre[cur]
    arr.append(cur)
    print(' '.join(map(str, arr[::-1])))

n, k = map(int, input().split())
dist = [987654321] * 100001
pre = [-1] * 100001
print(bfs(n))
route(k)