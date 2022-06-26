n, m, k = map(int, input().split())

cache = [-1] * 201
def factorial(i):
    global cache
    if cache[i] != -1:
        return cache[i]
    if i < 2:
        cache[i] = 1
        return 1
    cache[i] = i * factorial(i - 1)
    return cache[i]

def nHm(n, m):
    return factorial(n + m) // (factorial(n) * factorial(m))

if k > nHm(n, m):
    print(-1)
else:
    cnt = 1
    result = ''
    while n > 0 and m > 0:
        compareNumber = nHm(n - 1, m)
        if k == cnt + compareNumber:
            result += 'z'
            m -= 1
            result += 'a' * n
            result += 'z' * m
            n, m = 0, 0
            cnt += compareNumber
        elif k < cnt + compareNumber:
            result += 'a'
            n -= 1
        else:
            result += 'z'
            m -= 1
            cnt += compareNumber
    if n > 0:
        result += 'a' * n
    if m > 0:
        result += 'z' * m

    print(result)