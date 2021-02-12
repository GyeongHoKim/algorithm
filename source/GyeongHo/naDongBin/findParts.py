n = int(input())
array = [0] * 1000001

for i in input().split():
	array[int(i)] = 1

m = int(input())
x = list(map(int, input().split()))

for i in x:
	if i in array:
		print('yes', end=' ')
	else:
		print('no', end=' ')
