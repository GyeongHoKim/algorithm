import sys
input = sys.stdin.readline
print = sys.stdout.write

def star(i, j, n):
    if ((i // n) % 3 == 1 and (j // n) % 3 == 1):
        print(' ')
    elif (n == 1):
        print('*')
    else:
        star(i, j, n // 3)

n = int(input())
for i in range(n):
    for j in range(n):
        star(i, j, n)
    print('\n')