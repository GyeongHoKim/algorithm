max_num = 10000
masking = [True] * 10001

def d(n):
    result = n
    tmp = str(n)
    for s in tmp:
        result += int(s)
    if result > 10000:
        return
    masking[result] = False
    d(result)

for i in range(1, max_num + 1):
    d(i)

for i in range(1, max_num + 1):
    if masking[i]:
        print(i)