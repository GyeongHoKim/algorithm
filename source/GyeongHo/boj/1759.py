from itertools import combinations
import sys
input = sys.stdin.readline
print = sys.stdout.write

l, c = map(int, input().split())
arr = input().split()
arr.sort()

result = list(combinations(arr, l))
for words in result:
    consonant = 0
    vowel = 0
    for word in words:
        if word in ['a', 'e', 'i', 'o', 'u']:
            consonant += 1
        else:
            vowel += 1
    if consonant >= 1 and vowel >= 2:
        print(''.join(words))
        print('\n')