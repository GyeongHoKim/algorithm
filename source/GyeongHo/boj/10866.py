import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
q = deque()
for _ in range(n):
    command = input().rstrip()
    if command == 'pop_front':
        if q:
            print(q.popleft())
        else:
            print(-1)
    elif command == 'pop_back':
        if q:
            print(q.pop())
        else:
            print(-1)
    elif command == 'size':
        print(len(q))
    elif command == 'empty':
        if q:
            print(0)
        else:
            print(1)
    elif command == 'front':
        if q:
            print(q[0])
        else:
            print(-1)
    elif command == 'back':
        if q:
            print(q[-1])
        else:
            print(-1)
    else:
        if command.split()[0] == 'push_front':
            q.appendleft(int(command.split()[1]))
        else:
            q.append(int(command.split()[1]))
