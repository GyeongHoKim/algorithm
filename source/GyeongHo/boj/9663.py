n = int(input())

def dfs(visited, cur):
    global n
    answer = 0
    if cur == n:
        return 1

    for col in range(n):
        visited[cur] = col
        for row in range(cur):
            if visited[row] == visited[cur]:
                break
            if abs(visited[cur] - visited[row]) == cur - row:
                break
        else:
            answer += dfs(visited, cur + 1)
    
    return answer

print(dfs([0] * n, 0))