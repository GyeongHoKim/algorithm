import sys
input = sys.stdin.readline

def timeCount(p, time):
    if p > time:
        return time - (p % time)
    else:
        return time - p

t = int(input())
for _ in range(t):
    p, a, b, c = map(int, input().split())
    print(min(timeCount(p, a), timeCount(p, b), timeCount(p, c)))