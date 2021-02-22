n = int(input())
timeList = []
for _ in range(n):
    a, b = map(int, input().split())
    timeList.append((b, a))
timeList.sort()

def solution(prev, start, count):
    while start < n:
        while timeList[prev][0] > timeList[start][1] and start < n:
            start += 1
        if start == n:
            return count
        else:
            count += 1
            prev = start
            start += 1
    return count

print(solution(0, 1, 1))
