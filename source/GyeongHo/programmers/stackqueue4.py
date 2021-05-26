from collections import deque

def solution(prices):
    n = len(prices)
    time = [0] * n
    time_idx = n - 2
    q = deque([prices.pop()])
    while prices:
        now = prices.pop()
        for compare in q:
            time[time_idx] += 1
            if compare < now:
                break
        q.appendleft(now)
        time_idx -= 1
    return time