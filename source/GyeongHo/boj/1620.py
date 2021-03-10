import sys
input = sys.stdin.readline

n, m = map(int, input().split())
pkmName = [0]
pkmNum = {}

for i in range(n):
	tmp = input().rstrip()
	pkmNum[tmp] = i + 1
	pkmName.append(tmp)

for _ in range(m):
	question = input().rstrip()
	if question.isdigit():
		print(pkmName[int(question)])
	else:
		print(pkmNum[question])
