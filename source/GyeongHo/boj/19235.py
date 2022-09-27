import sys
input = sys.stdin.readline

n = int(input())
ans = 0
blueBlocks = []
greenBlocks = []
board = [[0] * 10 for _ in range(10)]

def inRange(block, t):
    flag = True
    for point in block:
        y, x = point[0], point[1]
        if t == 'b' and 0 <= y < 4 and 0 <= x < 10 and board[y][x] == 0:
            continue
        if t == 'g' and 0 <= y < 10 and 0 <= x < 4 and board[y][x] == 0:
            continue
        flag = False
    return flag
        

def sliding(y, x):
    global blueBlocks, greenBlocks
    # blue
    block = [[y, x]]
    if t == 2:
        block.append([y, x + 1])
    if t == 3:
        block.append([y + 1, x])
    while inRange(block, 'b'):
        for point in block:
            point[1] += 1
    for point in block:
        point[1] -= 1
        board[point[0]][point[1]] = 1
    blueBlocks.append(block)
    # green
    block = [[y, x]]
    if t == 2:
        block.append([y, x + 1])
    if t == 3:
        block.append([y + 1, x])
    while inRange(block, 'g'):
        for point in block:
            point[0] += 1
    for point in block:
        point[0] -= 1
        board[point[0]][point[1]] = 1
    greenBlocks.append(block)

def scoring():
    global blueBlocks, greenBlocks
    score = 0
    # blue
    for j in range(4, 10):
        flag = True
        remain = [True] * len(blueBlocks)
        for i in range(4):
            if board[i][j] == 0:
                flag = False
        if flag:
            score += 1
            for i in range(4):
                board[i][j] = 0
                for k in range(len(blueBlocks)):
                    if [i, j] in blueBlocks[k]:
                        if len(blueBlocks[k]) == 1:
                            remain[k] = False
                        else:
                            blueBlocks[k].remove([i, j])
        blueBlocks = [blueBlocks[x] for x in range(len(blueBlocks)) if remain[x]]
    # green
    for i in range(4, 10):
        flag = True
        remain = [True] * len(greenBlocks)
        for j in range(4):
            if board[i][j] == 0:
                flag = False
        if flag:
            score += 1
            for j in range(4):
                board[i][j] = 0
                for k in range(len(greenBlocks)):
                    if [i, j] in greenBlocks[k]:
                        if len(greenBlocks[k]) == 1:
                            remain[k] = False
                        else:
                            greenBlocks[k].remove([i, j])
        greenBlocks = [greenBlocks[x] for x in range(len(greenBlocks)) if remain[x]]
    return score

def reSliding():
    global blueBlocks, greenBlocks
    # blue
    for block in blueBlocks:
        for point in block:
            board[point[0]][point[1]] = 0
        while inRange(block, 'b'):
            for point in block:
                point[1] += 1
        for point in block:
            point[1] -= 1
            board[point[0]][point[1]] = 1
    # green
    for block in greenBlocks:
        for point in block:
            board[point[0]][point[1]] = 0
        while inRange(block, 'g'):
            for point in block:
                point[0] += 1
        for point in block:
            point[0] -= 1
            board[point[0]][point[1]] = 1
            
def eleminating():
    global blueBlocks, greenBlocks
    # blue
    rightPush = 0
    for j in range(4, 6):
        flag = False
        for i in range(4):
            if board[i][j] == 1:
                flag = True
        if flag:
            rightPush += 1
    for k in range(rightPush):
        j = 9 - k
        for i in range(4):
            remain = [True] * len(blueBlocks)
            if board[i][j] == 1:
                board[i][j] = 0
                for w in range(len(blueBlocks)):
                    if [i, j] in blueBlocks[w]:
                        if len(blueBlocks[w]) == 1:
                            remain[w] = False
                        else:
                            blueBlocks[w].remove([i, j])
            blueBlocks = [blueBlocks[x] for x in range(len(blueBlocks)) if remain[x]]
    # green
    downPush = 0
    for i in range(4, 6):
        flag = False
        for j in range(4):
            if board[i][j] == 1:
                flag = True
        if flag:
            downPush += 1
    for k in range(downPush):
        i = 9 - k
        for j in range(4):
            remain = [True] * len(greenBlocks)
            if board[i][j] == 1:
                board[i][j] = 0
                for w in range(len(greenBlocks)):
                    if [i, j] in greenBlocks[w]:
                        if len(greenBlocks[w]) == 1:
                            remain[w] = False
                        else:
                            greenBlocks[w].remove([i, j])
            greenBlocks = [greenBlocks[x] for x in range(len(greenBlocks)) if remain[x]]

for _ in range(n):
    t, y, x = map(int, input().split())
    sliding(y, x)
    tmp = scoring()
    while tmp > 0:
        ans += tmp
        reSliding()
        tmp = scoring()
    eleminating()
    reSliding()
print(ans)
ans = 0
for i in range(10):
    for j in range(10):
        if board[i][j] == 1:
            ans += 1
print(ans)