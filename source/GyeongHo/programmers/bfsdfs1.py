def solution(numbers, target, idx = 0, depth = 0):
    count = 0
    if sum(numbers) == target:
        if depth == 0:
            count += 1
        else:
            return 1
    for i in range(idx, len(numbers)):
        numbers[i] *= -1
        count += solution(numbers, target, i + 1, depth + 1)
        numbers[i] *= -1
    return count