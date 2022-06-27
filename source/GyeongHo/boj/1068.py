import sys
input = sys.stdin.readline

root = 0
n = int(input())
parent = list(map(int, input().split()))
deleteNode = int(input())

graph = [[] for _ in range(n)]
for i in range(n):
    if parent[i] == -1:
        root = i
        continue
    graph[parent[i]].append(i)

def delNode(node):
    if len(graph[node]) == 0:
        for i in range(n):
            if node in graph[i]:
                graph[i].remove(node)
        return
    for element in graph[node]:
        delNode(element)
    for i in range(n):
        if node in graph[i]:
            graph[i].remove(node)

def cntNode(node):
    global cnt
    if len(graph[node]) == 0:
        cnt += 1
        return
    for element in graph[node]:
        cntNode(element)
    return

if deleteNode == root or n == 1:
    print(0)
else:
    delNode(deleteNode)
    cnt = 0
    cntNode(root)
    print(cnt)