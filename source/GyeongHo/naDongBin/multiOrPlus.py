data = input()

result = int(data[0])
for i in range(2, len(data)):
	num = int(data[i])
	if num <= 1 or result <= 1:
		result += num
	else:
		result *= num

print(result)
