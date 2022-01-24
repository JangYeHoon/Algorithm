# 괄호변환(dfs)

mx, my = [-1, 1, 0, 0], [0, 0, -1, 1]

def dfs(x, y):
    matrix[x][y] = 1
    for i in range(4):
        nx = x + mx[i]
        ny = y + my[i]

        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        if not(matrix[nx][ny]):
            dfs(nx, ny)

N, M = map(int, input().split())
matrix = []

for _ in range(N):
    matrix.append(list(map(int, input())))

result = 0
for i in range(N):
    for j in range(M):
        if not(matrix[i][j]):
            result += 1
            dfs(i, j)
print(result)