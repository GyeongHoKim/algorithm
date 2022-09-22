from collections import deque
graph = [[] for _ in range(17)]
isWolf = []
visited = [[0] * 17 for _ in range(1 << 17)]

def calAnimal(bitmask):
    n = len(isWolf)
    sheep = 0
    wolf = 0
    for i in range(n):
        if bitmask & (1 << i):
            if isWolf[i]:
                wolf += 1
            else:
                sheep += 1
    return (sheep, wolf)

def bfs():
    maxSheep = 0
    q = deque([(0, 1)])
    visited[1][0] = 1
    while q:
        cur, bitmask = q.popleft()
        for nxt in graph[cur]:
            nxtBitmask = bitmask | (1 << nxt)
            nxtSheep, nxtWolf = calAnimal(nxtBitmask)
            if visited[nxtBitmask][nxt] > 0 or nxtSheep <= nxtWolf:
                continue
            visited[nxtBitmask][nxt] = nxtSheep
            q.append((nxt, nxtBitmask))
            maxSheep = max(maxSheep, nxtSheep)
    return maxSheep

def solution(info, edges):
    global isWolf
    isWolf = info
    for edge in edges:
        a, b = edge
        graph[a].append(b)
        graph[b].append(a)
    return bfs()

print(solution([0,0,1,1,1,0,1,0,1,0,1,1], [[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))
print(solution([0,1,0,1,1,0,1,0,0,1,0], [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6],[3,7],[4,8],[6,9],[9,10]]))