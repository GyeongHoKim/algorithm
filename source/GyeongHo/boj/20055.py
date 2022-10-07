import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
durability = deque(list(map(int, input().split())))
robots = deque([0] * n)
turn = 1

while True:
    # rotate
    durability.rotate(1)
    robots.rotate(1)
    robots[-1] = 0

    # robot move
    for i in range(n - 2, -1, -1):
        if robots[i] == 0:
            continue
        nxt = i + 1
        if robots[nxt] == 0 and durability[nxt] > 0:
            durability[nxt] -= 1
            robots[i] = 0
            if nxt != n - 1:
                robots[nxt] = 1

    # new robot
    if durability[0] > 0:
        durability[0] -= 1
        robots[0] = 1

    # count 0 durability
    if sum(list(map(lambda x: x <= 0, durability))) >= k:
        break
    turn += 1

print(turn)