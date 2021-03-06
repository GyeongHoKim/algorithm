n = int(input())
horrorList = list(map(int, input().split()))
horrorList.sort()

group, count = 0, 0

for i in horrorList:
	count += 1
	if count >= i:
		group += 1
		count = 0

print(group)
