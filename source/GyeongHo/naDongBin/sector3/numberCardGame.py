import sys
input = sys.stdin.readline

max_val = 0
n, m = map(int, input().split())
for _ in range(n):
    tmp = list(map(int, input().split()))
    max_val = max(max_val, min(tmp))
print(max_val)