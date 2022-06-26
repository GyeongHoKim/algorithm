import sys
input = sys.stdin.readline

def H(n):
    if n < 100:
        return True
    arr = [int(x) for x in str(n)]
    d = arr[1] - arr[0]
    for i in range(len(arr) - 1):
        if arr[i] + d != arr[i + 1]:
            return False
    return True

n = int(input())
result = 0
for i in range(1, n + 1):
    if (H(i)):
        result += 1
print(result)