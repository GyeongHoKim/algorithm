import sys
input = sys.stdin.readline

h = [0] * 201
w = [0] * 201
ans = [1] * 201

n = int(input())
for i in range(n):
    w[i], h[i] = map(int, input().split())

for i in range(n):
    for j in range(n):
        if (i == j):
            continue
        if (w[i] < w[j] and h[i] < h[j]):
            ans[i] += 1

for i in range(n):
    print(ans[i], end=' ')