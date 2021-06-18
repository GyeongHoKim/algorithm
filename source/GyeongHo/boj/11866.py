n, k = map(int, input().split())
arr = [x for x in range(1, n + 1)]
answer = []
idx = 0

while arr:
    idx = (idx + k - 1) % len(arr)
    answer.append(arr.pop(idx))

print('<', end='')
print(', '.join(map(str, answer)), end='')
print('>')