a, b, c = map(int, input().split())
def split_pow(a, b, c):
    res = 1
    while b:
        if b & 1:
            res = a * res % c
        a = a * a % c
        b >>= 1
    return res

def recursion_split_pow(a, b, c):
    if b == 0:
        return 1
    res = recursion_split_pow(a, b // 2)
    if b & 1:
        return res * res * a % c
    else:
        return res * res % c

print(split_pow(a, b, c))