encoded = input()
arr = [int(x) for x in encoded if x.isnumeric()]
if len(encoded) != len(arr) or arr[0] == 0:
    print(0)
    exit(0)
elif len(arr) == 1:
    print(1)
    exit(0)

dp = [0] * len(arr)
dp[0] = 1
if arr[0] * 10 + arr[1] > 26:
    if arr[1] == 0:
        print(0)
        exit(0)
    dp[1] = 1
elif arr[1] == 0:
    dp[1] = 1
else:
    dp[1] = 2

for i in range(2, len(arr)):
    if arr[i] == 0 and (arr[i - 1] * 10 + arr[i] > 26 or arr[i - 1] == 0):
        print(0)
        exit(0)
    dp[i] = (dp[i - 1] % 1000000 if arr[i] != 0 else 0) + (dp[i - 2] % 1000000 if arr[i - 1] * 10 + arr[i] <= 26 and arr[i - 1] != 0 else 0)
    dp[i] %= 1000000

print(dp[-1])
