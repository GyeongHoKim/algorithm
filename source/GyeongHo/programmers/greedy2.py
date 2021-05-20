def solution(name):
    idx, ans = 0, 0
    ansList = [min(ord(i) - ord('A'), ord('Z') - ord(i) + 1) for i in name]
    while True:
        ans += ansList[idx]
        ansList[idx] = 0
        if sum(ansList) == 0:
            break
        left, right = 1, 1
        while ansList[idx - left] == 0:
            left += 1
        while ansList[idx + right] == 0:
            right += 1
        ans += left if left < right else right
        idx += -left if left < right else right
    return ans