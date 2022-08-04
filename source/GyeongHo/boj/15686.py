from itertools import combinations

n, m = map(int, input().split())
city = [[0] * n for _ in range(n)]
dist = 987654321
houses = []
chicken = []

for i in range(n):
    tmp = list(map(int, input().split()))
    for j in range(n):
        if tmp[j] == 1:
            city[i][j] = 1
            houses.append((i, j))
        elif tmp[j] == 2:
            city[i][j] = 2
            chicken.append((i, j))

for case in combinations(chicken, m):
    sum = 0
    for house in houses:
        sum += min([abs(house[0] - i[0]) + abs(house[1] - i[1]) for i in case])
        if dist <= sum:
            break
    else:
        dist = sum
print(dist)