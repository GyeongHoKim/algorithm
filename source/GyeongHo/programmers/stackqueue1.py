from collections import deque
def solution(progresses, speeds):
    rest = deque([100] * len(progresses))
    answer = []
    length_rest = len(rest)
    for i in range(length_rest):
        tmp = rest[i] - progresses[i]
        if tmp % speeds[i] == 0:
            rest[i] = (rest[i] - progresses[i]) // speeds[i]
        else:
            rest[i] = (rest[i] - progresses[i]) // speeds[i] + 1
    
    while rest:
        now_progress = rest.popleft()
        cnt = 1
        while rest:
            next_progress = rest[0]
            if now_progress < next_progress:
                break
            else:
                cnt += 1
                rest.popleft()
        answer.append(cnt)
    
    return answer