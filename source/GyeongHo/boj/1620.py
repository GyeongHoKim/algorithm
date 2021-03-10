import sys
input = sys.stdin.readline

n, m = map(int, input().split())
d = {}
for i in range(1, n + 1):
	d[i] = input()

for _ in range(m):
	question = input()
	if question.isalpha():
		for number, name in d.items():
			if name == question:
				print(number)
	else:
		print(d[int(question)])
