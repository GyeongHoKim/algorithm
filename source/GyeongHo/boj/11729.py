dp = [0 for i in range(21)]
dp[1] = 1
for i in range(2, 21):
    dp[i] = dp[i - 1] * 2 + 1

def hanoi(position, target, number):
    if number == 1:
        print(position, target)
        return
    next = 6 - position - target
    hanoi(position, next, number - 1)
    hanoi(position, target, 1)
    hanoi(next, target, number - 1)
    return

n = int(input())
print(dp[n])
hanoi(1, 3, n)