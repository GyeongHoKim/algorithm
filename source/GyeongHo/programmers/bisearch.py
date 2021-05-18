def solution(n, times):
    max_time = max(times) * n
    min_time = 1
    answer = 0
    while min_time <= max_time:
        mid_time = (max_time + min_time) // 2
        immigrated = sum([mid_time // time for time in times])
        if immigrated >= n:
            answer = mid_time
            max_time = mid_time - 1
        else:
            min_time = mid_time + 1
    return answer