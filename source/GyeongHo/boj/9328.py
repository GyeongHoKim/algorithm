from collections import deque
import sys
input = sys.stdin.readline

t = int(input())
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

def bfs(start_y, start_x, visited, building, keys):
    q = deque([(start_y, start_x)])
    visited[start_y][start_x] = True
    cnt = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny < 0 or ny >= n + 2 or nx < 0 or nx >= m + 2 or building[ny][nx] == '*' or visited[ny][nx]:
                continue
            if building[ny][nx] == '$':
                q.append((ny, nx))
                visited[ny][nx] = True
                building[ny][nx] = '.'
                cnt += 1
            if building[ny][nx].islower():
                q = deque([(ny, nx)])
                visited = [[False] * (m + 2) for _ in range(n + 2)]
                visited[ny][nx] = True
                keys[ord(building[ny][nx]) - ord('a')] = True
                building[ny][nx] = '.'
            if building[ny][nx].isupper() and keys[ord(building[ny][nx]) - ord('A')]:
                q.append((ny, nx))
                visited[ny][nx] = True
                building[ny][nx] = '.'
            if building[ny][nx] == '.':
                q.append((ny, nx))
                visited[ny][nx] = True
    return cnt

for _ in range(t):
    n, m = map(int, input().split())
    building = [['.'] * (m + 2) for _ in range(n + 2)]
    visited = [[False] * (m + 2) for _ in range(n + 2)]
    keys = [False] * 26
    for i in range(1, n + 1):
        line = input().rstrip()
        for j in range(1, m + 1):
            building[i][j] = line[j - 1]
    tmp = input().rstrip()
    if tmp != "0":
        for i in tmp:
            keys[ord(i) - ord('a')] = True
    
    print(bfs(0, 0, visited, building, keys))