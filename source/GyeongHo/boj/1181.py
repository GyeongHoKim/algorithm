import sys
input = sys.stdin.readline

n = int(input())
array = [input().rstrip() for _ in range(n)]
array = list(set(array))
lengthArray = [(word, len(word)) for word in array]
lengthArray.sort(key = lambda x: (x[1], x[0]))
for chunk in lengthArray:
    print(chunk[0])