t = int(input())
for _ in range(t):
    parenthesis = input()
    if parenthesis[0] == ')':
        print("NO")
        continue
    rightOpen = 0
    leftOpen = 0
    for word in parenthesis:
        if rightOpen < leftOpen:
            break
        if word == '(':
            rightOpen += 1
        else:
            leftOpen += 1
    if rightOpen == leftOpen:
        print("YES")
    else:
        print("NO")