from collections import deque

n = int(input())
q = [e for e in range(1, n + 1)]

def cardRemove(q):
    cards = deque(q)
    while len(cards) > 1:
        cards.popleft()
        cards.append(cards.popleft())
    return cards.popleft()

print(cardRemove(q))
