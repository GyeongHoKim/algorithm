import sys
input = sys.stdin.readline

cnt = [0] * 8001
ans = [0] * 4
avgSum = 0.0
max_freq = 0
max_num = -4001
min_num = 4001

n = int(input())
for i in range(n):
    tmp = int(input())
    avgSum += tmp
    cnt[tmp + 4000] += 1
    if cnt[tmp + 4000] > max_freq:
        max_freq = cnt[tmp + 4000]
    if tmp < min_num:
        min_num = tmp
    if tmp > max_num:
        max_num = tmp

arr = [0] * n
idx = 0
freq = []
for i in range(8001):
    if cnt[i]:
        for _ in range(cnt[i]):
            arr[idx] = i - 4000
            idx += 1
        if cnt[i] == max_freq:
            freq.append(i - 4000)

ans[0] = int(round(avgSum / n, 0))
ans[1] = arr[n // 2]
if len(freq) > 1:
    ans[2] = freq[1]
else:
    ans[2] = freq[0]
ans[3] = max_num - min_num

for i in ans:
    print(i)