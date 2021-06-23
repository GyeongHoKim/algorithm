# https://programmers.co.kr/learn/courses/30/lessons/77484

def solution(lottos, win_nums):
    cnt = 0
    right = 0
    for lotto in lottos:
        if lotto == 0:
            cnt += 1
        else:
            if lotto in win_nums:
                right += 1
    best = 7 - (cnt + right)
    worst = 7 - right
    if best == 7:
        best = 6
    if worst == 7:
        worst = 6
    
    return [best, worst]