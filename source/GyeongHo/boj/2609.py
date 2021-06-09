def gcd(larger, smaller):
    if smaller == 0:
        return larger
    else:
        return gcd(smaller, larger % smaller)

larger, smaller = map(int, input().split())
if larger < smaller:
    larger, smaller = smaller, larger

GCD = gcd(larger, smaller)
LCM = smaller * (larger // GCD)
print(GCD)
print(LCM)