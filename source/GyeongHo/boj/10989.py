import sys
input = sys.stdin.readline

n = int(input())
count = [0] * 10001

for _ in range(n):
    temp = int(input())
    count[temp] += 1

for i in range(10001):
    for j in range(count[i]):
        sys.stdout.write(str(i) + '\n')