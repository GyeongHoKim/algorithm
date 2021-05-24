from collections import deque
def solution(priorities, location):
    print_q = deque(priorities)
    cnt = 0

    while print_q:
        max_priority = max(print_q)
        if max_priority == print_q[0]:
            print_q.popleft()
            cnt += 1
            if location == 0:
                return cnt
            else:
                location -= 1
        else:
            print_q.rotate(-1)
            if location == 0:
                location = len(print_q) - 1
            else:
                location -= 1
    return cnt