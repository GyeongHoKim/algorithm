n = int(input())
scareList = list(map(int, input().split()))
scareList.append(0)
scareList.sort(reverse=True)

def countGroup(i):
    group = 0
    while i < n:
        group += 1
        i += scareList[i]
    return group

maxCount = 0
for i in range(n):
    maxCount = max(maxCount, countGroup(i))
    
print(maxCount)
