def solution(board, skill):
    n, m = len(board), len(board[0])
    acc = [[0] * (m + 1) for _ in range(n + 1)]
    result = 0
    for instr in skill:
        _type, r1, c1, r2, c2, degree = instr
        if _type == 1:
            degree *= -1
        acc[r1][c1] -= degree
        acc[r1][c2 + 1] += degree
        acc[r2 + 1][c1] += degree
        acc[r2 + 1][c2 + 1] -= degree
    for i in range(n + 1):
        for j in range(1, m + 1):
            acc[i][j] += acc[i][j - 1]
    for j in range(m + 1):
        for i in range(1, n + 1):
            acc[i][j] += acc[i - 1][j]
    for i in range(n):
        for j in range(m):
            if board[i][j] - acc[i][j] >= 1:
                result += 1
    return result

print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]], [[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]))