n, m = map(int, input().split())
office = [[0] * m for _ in range(n)]
dy = [0, -1, 0, 1]
dx = [-1, 0, 1, 0]
cctvs = []
ans = 987654321

for i in range(n):
    tmp = list(map(int, input().split()))
    for j in range(m):
        office[i][j] = tmp[j]
        if 0 < tmp[j] < 6:
            cctvs.append((i, j, tmp[j]))

def inRange(y, x):
    if 0 <= y < n and 0 <= x < m:
        return True
    return False

def change(cctv, dir):
    y, x, t = cctv[0], cctv[1], cctv[2]
    if t == 2 and dir > 1:
        return False
    if t == 5 and dir > 0:
        return False

    while True:
        y += dy[dir % 4]
        x += dx[dir % 4]
        if not inRange(y, x) or office[y][x] == 6:
            break
        if office[y][x] <= 0:
            office[y][x] -= 1
    if t ==2 or t == 4 or t == 5:
        y, x = cctv[0], cctv[1]
        while True:
            y += dy[(dir + 2) % 4]
            x += dx[(dir + 2) % 4]
            if not inRange(y, x) or office[y][x] == 6:
                break
            if office[y][x] <= 0:
                office[y][x] -= 1
    if t == 3 or t == 4 or t == 5:
        y, x = cctv[0], cctv[1]
        while True:
            y += dy[(dir + 1) % 4]
            x += dx[(dir + 1) % 4]            
            if not inRange(y, x) or office[y][x] == 6:
                break
            if office[y][x] <= 0:
                office[y][x] -= 1
    if t == 5:
        y, x = cctv[0], cctv[1]
        while True:
            y += dy[(dir + 3) % 4]
            x += dx[(dir + 3) % 4]            
            if not inRange(y, x) or office[y][x] == 6:
                break
            if office[y][x] <= 0:
                office[y][x] -= 1
    return True

def recover(cctv, dir):
    y, x, t = cctv[0], cctv[1], cctv[2]
    if t == 2 and dir > 1:
        return False
    if t == 5 and dir > 0:
        return False

    while True:
        y += dy[dir]
        x += dx[dir]
        if not inRange(y, x) or office[y][x] == 6:
            break
        if office[y][x] < 0:
            office[y][x] += 1
    if t ==2 or t == 4 or t == 5:
        y, x = cctv[0], cctv[1]
        while True:
            y += dy[(dir + 2) % 4]
            x += dx[(dir + 2) % 4]
            if not inRange(y, x) or office[y][x] == 6:
                break
            if office[y][x] < 0:
                office[y][x] += 1
    if t == 3 or t == 4 or t == 5:
        y, x = cctv[0], cctv[1]
        while True:
            y += dy[(dir + 1) % 4]
            x += dx[(dir + 1) % 4]
            if not inRange(y, x) or office[y][x] == 6:
                break
            if office[y][x] < 0:
                office[y][x] += 1
    if t == 5:
        y, x = cctv[0], cctv[1]
        while True:
            y += dy[(dir + 3) % 4]
            x += dx[(dir + 3) % 4]
            if not inRange(y, x) or office[y][x] == 6:
                break
            if office[y][x] < 0:
                office[y][x] += 1
    return True

def dfs(depth):
    global ans
    if depth >= len(cctvs):
        cnt = 0
        for i in range(n):
            for j in range(m):
                if office[i][j] == 0:
                    cnt += 1

        ans = min(ans, cnt)
        return
    for i in range(4):
        if not change(cctvs[depth], i):
            continue
        dfs(depth + 1)
        recover(cctvs[depth], i)
        
dfs(0)
print(ans)