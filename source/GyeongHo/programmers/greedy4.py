def solution(people, limit):
    people.sort()
    answer = 0
    start_idx = 0
    last_idx = len(people) - 1
    
    while start_idx <= last_idx:
        if people[start_idx] + people[last_idx] <=limit:
            start_idx += 1
        last_idx -= 1
        answer += 1
    return answer