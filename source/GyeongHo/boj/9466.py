import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

visited = [False] * 100001
selection = [0] * 100001
memoization = [False] * 100001

def howManyNodesInCycle(i, cur):
    number = 0
    while i != cur:
        i = selection[i]
        number += 1
    return number + 1

def dfs(cur):
    global cnt
    if memoization[cur]:
        return
    if visited[cur]:
        cnt += howManyNodesInCycle(selection[cur], cur)
        return
    visited[cur] = True
    dfs(selection[cur])
    visited[cur] = False
    memoization[cur] = True

t = int(input())
while t > 0:
    n = int(input())
    cnt = 0
    tmp = list(map(int, input().split()))
    for i in range(1, n + 1):
        visited[i] = False
        memoization[i] = False
        selection[i] = tmp[i - 1]
    for i in range(1, n + 1):
        dfs(i)
    print(n - cnt)
    t -= 1