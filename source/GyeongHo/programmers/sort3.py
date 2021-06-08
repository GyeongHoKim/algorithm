def solution(citations):
    citations.sort()
    n = len(citations)
    for i in range(n, 0, -1):
        if citations[n - i] >= i:
            return i
    return 0