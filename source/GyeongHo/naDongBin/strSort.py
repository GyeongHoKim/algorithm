number = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
result = 0

word = list(input())
for i in range(len(word)):
	if word[i] in number:
		result += int(word.pop(i))

word.sort(cmp = lambda a, b: ord(a) - ord(b))
print(word + str(result))
