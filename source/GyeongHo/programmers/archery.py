maxDiff = 0
idealLion = [-1]

def calDiff(info, Lion):
    Apache = 0
    Leon = 0
    for i in range(11):
        if info[i] < Lion[i]:
            Leon += 10 - i
        if Lion[i] <= info[i] and info[i] > 0:
            Apache += 10 - i
    return Leon - Apache

def dfs(info, Lion, cur, n):
    global maxDiff, idealLion
    if n < 0:
        return
    if cur < 0:
        diff = calDiff(info, Lion)
        if maxDiff < diff:
            maxDiff = diff
            idealLion = [x for x in Lion]
            idealLion[10] += n
        return
    Lion[cur] = info[cur] + 1
    dfs(info, Lion, cur - 1, n - Lion[cur])
    Lion[cur] = 0
    dfs(info, Lion, cur - 1, n)

def solution(n, info):
    Lion = [0] * 11
    dfs(info, Lion, 10, n)
    return idealLion

print(solution(10, [0,0,0,0,0,0,0,0,3,4,3]))