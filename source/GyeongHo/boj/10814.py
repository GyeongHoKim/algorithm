import sys
input = sys.stdin.readline
n = int(input())
arr = [list(map(lambda x: int(x) if x.isnumeric() else x, input().split())) for _ in range(n)]

arr.sort(key=lambda x: x[0])

for element in arr:
    print(element[0], element[1])