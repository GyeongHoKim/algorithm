# https://programmers.co.kr/learn/courses/30/lessons/72410
def solution(new_id):
    new_id = new_id.lower()
    new_id = list(new_id)
    new_id = list(filter(lambda x: x.isalnum() or x == '-' or x == '_' or x == '.', new_id))
    tmp = [new_id[0]]
    for i in range(1, len(new_id)):
        if tmp[-1] == '.' and new_id[i] == '.':
            continue
        tmp.append(new_id[i])
    new_id = tmp
    if new_id[0] == '.':
        if len(new_id) == 1:
            new_id[0] = 'a'
        else:
            new_id.pop(0)
    if new_id[-1] == '.':
        new_id.pop()
    if len(new_id) > 15:
        new_id = new_id[:15]
        while new_id[-1] == '.':
            new_id.pop()
    while len(new_id) < 3:
        new_id.append(new_id[-1])

    return ''.join(new_id)