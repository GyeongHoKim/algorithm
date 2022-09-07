import sys
from collections import deque
input = sys.stdin.readline
INF = 987654321
dy = [0, 0, -1, 1]
dx = [-1, 1, 0, 0]

def dfs(depth = 1):
    global v, ans
    if depth >= v:
        cost = 0
        for i in range(v - 1):
            cost += edges[nodes[order[i]][0]][nodes[order[i]][1]][nodes[order[i + 1]][0]][nodes[order[i + 1]][1]]
        ans = min(ans, cost)
        return
    for i in range(1, v):
        if visited[i]:
            continue
        order.append(i)
        visited[i] = True
        dfs(depth + 1)
        order.pop()
        visited[i] = False
        
def inRange(y, x):
    if 0 <= y < h and 0 <= x < w:
        return True
    return False

def bfs(start):
    q = deque([start])
    distance[start[0]][start[1]] = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if not inRange(ny, nx) or floor[ny][nx] == 1 or distance[ny][nx] <= distance[y][x] + 1:
                continue
            q.append((ny, nx))
            distance[ny][nx] = distance[y][x] + 1

while True:
    w, h = map(int, input().split())
    if (w, h) == (0, 0):
        exit(0)
    floor = [[0] * w for _ in range(h)]
    nodes = deque()
    edges = [[[[0] * 20 for _ in range(20)] for _ in range(20)] for _ in range(20)]
    for i in range(h):
        tmp = input()
        for j in range(w):
            if tmp[j] == 'o':
                nodes.appendleft((i, j))
            elif tmp[j] == '*':
                nodes.append((i, j))
            elif tmp[j] == 'x':
                floor[i][j] = 1

    v = len(nodes)
    for node in nodes:
        distance = [[INF] * w for _ in range(h)]
        bfs(node)
        for otherNode in nodes:
            if node == otherNode:
                continue
            edges[node[0]][node[1]][otherNode[0]][otherNode[1]] = distance[otherNode[0]][otherNode[1]]

    ans = INF
    order = deque([0])
    visited = [False] * v
    visited[0] = True
    dfs()
    if ans >= INF:
        ans = -1
    print(ans)