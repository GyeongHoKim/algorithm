def possible(S, T, lengthT, lengthS):
	for i in range(lengthT - 1, lengthS - 1, -1):
		if T[i] == 'A':
			T.pop(i)
		else:
			T.pop(i)
			T.reverse()
	if S == T:
		return True
	return False

S = list(input())
T = list(input())

if possible(S, T, len(T), len(S)):
	print(1)
else:
	print(0)