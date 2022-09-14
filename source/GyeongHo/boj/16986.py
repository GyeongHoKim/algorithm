from itertools import permutations
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
table = [list(map(int, input().split())) for _ in range(n)]
expectation = [[0] * 20 for _ in range(20)]
expectation[1] = list(map(int, input().split()))
expectation[2] = list(map(int, input().split()))
allCase = list(permutations([x for x in range(n)]))

def simulation(case):
    expectation[0] = case
    index = [0, 0, 0]
    turns = [True, True, False]
    win = [0, 0, 0]
    while win[0] < k and win[1] < k and win[2] < k and index[0] < n and index[1] < 20 and index[2] < 20:
        J, G, M = expectation[0][index[0]], expectation[1][index[1]] - 1, expectation[2][index[2]] - 1
        if not turns[0]:
            index[1] += 1
            index[2] += 1
            turns[0] = True
            if table[G][M] == 2:
                win[1] += 1
                turns[2] = False
            else:
                win[2] += 1
                turns[1] = False
        elif not turns[1]:
            index[0] += 1
            index[2] += 1
            turns[1] = True
            if table[J][M] == 2:
                win[0] += 1
                turns[2] = False
            else:
                win[2] += 1
                turns[0] = False
        elif not turns[2]:
            index[0] += 1
            index[1] += 1
            turns[2] = True
            if table[J][G] == 2:
                win[0] += 1
                turns[1] = False
            else:
                win[1] += 1
                turns[0] = False
    if win[0] >= k:
        return True
    return False

for case in allCase:
    if simulation(case):
        print(1)
        break
else:
    print(0)