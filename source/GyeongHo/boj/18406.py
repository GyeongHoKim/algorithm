n = list(map(int, input()))
nlength = len(n)

if sum(n[0:nlength//2]) == sum(n[nlength//2:nlength]):
	print("LUCKY")
else:
	print("READY")
