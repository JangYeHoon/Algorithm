# 공유기설치, 중량제한, 트리순회, 트리의 높이와 너비, 최소힙

N, M = map(int, input().split())
arr = []

for _ in range(N):
    arr.append(list(input()))

n_row = [0] * N
n_col = [0] * M
for i in range(N):
    for j in range(M):
        if arr[i][j] == 'X':
            n_row[i] = 1
            n_col[j] = 1

row_num = 0
col_num = 0

for i in range(N):
    if n_row[i] == 0:
        row_num += 1

for i in range(M):
    if n_col[i] == 0:
        col_num += 1

print(max(row_num, col_num))