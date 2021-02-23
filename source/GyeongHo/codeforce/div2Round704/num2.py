import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    original_deck = list(map(int, input().split()))
    chkList = [False] * (n + 1)
    last_num = original_deck[0]
    chkList[0] = True
    chkList[n] = True
    for i in range(1, n):
        if last_num < original_deck[i]:
            chkList[i] = True
            last_num = original_deck[i]

    for i in range(n - 1, -1, -1):
        if chkList[i]:
            j = i + 1
            print(original_deck[i], end=' ')
            while not chkList[j]:
                print(original_deck[j], end=' ')
                j += 1
    print()
