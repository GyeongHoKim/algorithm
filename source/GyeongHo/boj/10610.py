def chk3(numbers):
	if not (0 in numbers):
		return False
	else:
		result = 0
		for num in numbers:
			result += num
		if result % 3 == 0:
			return  True
	return False

n = list(map(int, input()))
if chk3(n):
	n.sort(reverse=True)
	for ele in n:
		print(ele, end='')
else:
	print(-1)
