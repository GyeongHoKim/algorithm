from collections import deque

n, k = map(int, input().split())
visited = [0] * 100001

def fluffyCow():
    global n, k, visited
    q = deque([n])
    while q:
        cur = q.popleft()
        if cur == k:
            return visited[cur]
        for i in [cur - 1, cur + 1, cur * 2]:
            if 0 <= i <= 100000 and visited[i] == 0:
                q.append(i)
                visited[i] = visited[cur] + 1
    return -1

print(fluffyCow())