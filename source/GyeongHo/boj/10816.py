n = int(input())
cards = list(map(int, input().split()))
m = int(input())
finds = list(map(int, input().split()))

hashTable = {}

for card in cards:
    tmp = hashTable.get(card)
    if tmp:
        hashTable[card] += 1
    else:
        hashTable[card] = 1

for find in finds:
    tmp = hashTable.get(find)
    if tmp:
        print(tmp, end=' ')
    else:
        print(0, end=' ')