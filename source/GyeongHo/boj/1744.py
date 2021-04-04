n = int(input())
result = 0
minus = []
notMinus = []
for _ in range(n):
    tmp = int(input())
    if tmp < 0:
        minus.append(tmp)
    else:
        notMinus.append(tmp)

minus.sort(reverse=True)
notMinus.sort(reverse=True)
if len(minus) % 2 != 0:
    result += minus.pop()
for i in range(0, len(minus), 2):
    result += minus[i] * minus[i + 1]

i = len(notMinus) - 1
while notMinus[i] < 2:
    result += notMinus.pop()
    i -= 1
if len(notMinus) % 2 != 0:
    result += notMinus.pop()
for i in range(0, len(notMinus), 2):
    result += notMinus[i] * notMinus[i + 1]

print(result)