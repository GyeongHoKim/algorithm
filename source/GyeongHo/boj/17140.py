# frequency 1순위, 수의 크기가 2순위
r, c, k = map(int, input().split())
r, c = r - 1, c - 1
time, row, col = 0, 3, 3
arr = [[0] * 100 for _ in range(100)]
for i in range(3):
    tmp = list(map(int, input().split()))
    for j in range(3):
        arr[i][j] = tmp[j]

def R():
    global row, col
    max_col = 0
    for i in range(row):
        dictionary = dict.fromkeys(arr[i], 0)
        for j in range(col):
            dictionary[arr[i][j]] += 1
        dictionary.pop(0)
        sorted_dict = sorted(dictionary.items())
        sorted_dict = sorted(sorted_dict, key = lambda x : x[1])
        idx = 0
        end = len(sorted_dict) if len(sorted_dict) <= 50 else 50
        for j in range(end):
            if idx >= 100:
                break
            arr[i][idx], arr[i][idx + 1] = sorted_dict[j][0], sorted_dict[j][1]
            idx += 2
        for k in range(end * 2, 100):
            arr[i][k] = 0
        max_col = max(max_col, end * 2)
    col = max_col
        
def C():
    global row, col
    max_row = 0
    for j in range(col):
        dictionary = dict()
        for i in range(row):
            dictionary[arr[i][j]] = dictionary.get(arr[i][j], 0) + 1
        if 0 in dictionary:
            dictionary.pop(0)
        sorted_dict = sorted(dictionary.items())
        sorted_dict = sorted(sorted_dict, key = lambda x : x[1])
        idx = 0
        end = len(sorted_dict) if len(sorted_dict) <= 50 else 50
        for i in range(end):
            if idx >= 100:
                break
            arr[idx][j], arr[idx + 1][j] = sorted_dict[i][0], sorted_dict[i][1]
            idx += 2
        for k in range(end * 2, 100):
            arr[k][j] = 0
        max_row = max(max_row, end * 2)
    row = max_row

while time < 101:
    if arr[r][c] == k:
        break
    elif row >= col:
        R()
    else:
        C()
    time += 1

print(-1 if time > 100 else time)