# https://programmers.co.kr/learn/courses/30/lessons/70128

def solution(a, b):
    result = 0
    for i, j in zip(a, b):
        result += i * j
    return result