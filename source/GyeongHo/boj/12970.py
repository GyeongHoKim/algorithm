def AB(S, n, k):
    if k > (n // 2) * (n // 2 + n % 2):
        return False
    elif k == 0:
        return True
    else:
        while True:
            if k < n:
                S[n - 1 - k] = 'A'
                return True
            else:
                idx = 0
                while S[idx] == 'A':
                    idx += 1
                S[idx] = 'A'
                k = k + idx - n + 2 + idx
                n -= idx

n, k = map(int, input().split())
S = ['B'] * n

if AB(S, n, k):
    for i in S:
        print(i, end='')
else:
    print(-1)