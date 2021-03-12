import sys
input = sys.stdin.readline

n, m = map(int, input().split())
hear = dict()
ansList = []
ans = 0

for i in range(n):
    tmp = input().rstrip()
    hear[tmp] = i + 1
for i in range(m):
    tmp = input().rstrip()
    if tmp in hear:
        ansList.append(tmp)
        ans += 1

ansList.sort()
print(ans)
for i in ansList:
    print(i)