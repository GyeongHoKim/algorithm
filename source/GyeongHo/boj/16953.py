a, b = map(int, input().split())
ans = 0
def dfs(a, b, cnt=1):
    global ans
    if a == b or a > b:
        if a == b:
            ans = cnt
            return True
        return False
    for i in [a * 10 + 1, a * 2]:
        if dfs(i, b, cnt + 1):
            return True

dfs(a, b)
if ans:
    print(ans)
else:
    print(-1)