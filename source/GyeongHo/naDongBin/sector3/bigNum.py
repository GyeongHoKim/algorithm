n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[n - 1]
second = data[n - 2]

result = (first * k + second) * m // (k + 1) + first * (m % (k + 1))
print(result)