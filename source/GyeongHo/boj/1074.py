n, r, c = map(int, input().split())
cnt = -1
flag = False


def z(n, y, x):
    global cnt, r, c, flag
    if flag:
        return
    if not (y <= r < y + 2 ** n and x <= c < x + 2 ** n):
        cnt += (2 ** n) ** 2
        return
    elif n == 1:
        for i in range(y, y + 2):
            for j in range(x, x + 2):
                cnt += 1
                if r == i and c == j:
                    flag = True
                    return

    z(n - 1, y, x)
    z(n - 1, y, x + 2 ** (n - 1))
    z(n - 1, y + 2 ** (n - 1), x)
    z(n - 1, y + 2 ** (n - 1), x + 2 ** (n - 1))


z(n, 0, 0)
if flag:
	print(cnt)
else:
	print('fuck')
