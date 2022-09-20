def kBase(n, k):
    changed = ""
    while n >= k:
        changed = str(n % k) + changed
        n //= k
    return str(n) + changed

def isPrime(n):
    if n < 2:
        return False
    i = 2
    while i ** 2 <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def solution(n, k):
    kBasedN = kBase(n, k)
    l = len(kBasedN)
    answer, p, q = 0, 0, 1
    if l == 1:
        return 1 if isPrime(int(kBasedN)) else 0
    while q < l:
        if kBasedN[q] == "0":
            subStr = kBasedN[p:q]
            if isPrime(int(subStr)):
                answer += 1
            p = q
            while p < l and kBasedN[p] == "0":
                p += 1
            q = p
        q += 1
    if isPrime(int(kBasedN[p:l] if p != l else 0)):
        answer += 1
    return answer

print(solution(1000000, 8))