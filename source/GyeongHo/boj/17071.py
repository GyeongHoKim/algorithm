# time limit is 0.25 sec. is it possible to solve with BFS, O(V^2)??
# maximum input is n = 500000 then (5 * 10^5)^2 = 2.5 * 10^11

from collections import deque

n, k = map(int, input().split())
visited = [[987654321] * 500001 for _ in range(2)]

def bfs(start, end):
    q = deque([(start, 0)])
    visited[0][start] = 0
    brother = [-1] * 500001
    while q:
        cur, time = q.popleft()
        for nxt in [cur - 1, cur + 1, cur * 2]:
            if nxt < 0 or nxt > 500000 or visited[(time + 1) % 2][nxt] <= time + 1:
                continue
            q.append((nxt, time + 1))
            visited[(time + 1) % 2][nxt] = time + 1
    brother[end] = 0
    step = 1
    cur = end
    while cur < 500001:
        if visited[brother[cur] % 2][cur] <= brother[cur]:
            return brother[cur]
        nxt = cur + step
        if nxt < 500001:
            brother[nxt] = brother[cur] + 1
        step += 1
        cur = nxt
    return -1

print(bfs(n, k))