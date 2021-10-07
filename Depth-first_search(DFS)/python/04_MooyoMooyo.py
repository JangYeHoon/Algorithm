# fast campus 강의
# https://www.acmicpc.net/problem/16768
# 1

def create_matrix(N):
    return [[False for i in range(10)] for _ in range(N)]

N, K = map(int, input().split())
matrix = [list(input()) for _ in range(N)]
check = create_matrix(N)
check2 = create_matrix(N)
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]

def dfs(x, y):
    ret = 1
    check[x][y] = True
    for i in range(4):
        mx, my = x + dx[i], y + dy[i]
        if mx < 0 or mx >= N or my < 0 or my >= 10:
            continue
        if check[mx][my] or matrix[x][y] != matrix[mx][my]:
            continue
        ret += dfs(mx, my)
    return ret

def dfs2(x, y, value):
    check2[x][y] = True
    matrix[x][y] = '0'
    for i in range(4):
        mx, my = x + dx[i], y + dy[i]
        if mx < 0 or mx >= N or my < 0 or my >= 10:
            continue
        if check2[mx][my] or matrix[mx][my] != value:
            continue
        dfs2(mx, my, value)

def down():
    for i in range(10):
        temp_list = []
        for j in range(N):
            if matrix[j][i] != '0':
                temp_list.append(matrix[j][i])
        for j in range(N - len(temp_list)):
            matrix[j][i] = '0'
        for j in range(N - len(temp_list), N):
            matrix[j][i] = temp_list[j - (N - len(temp_list))]

while True:
    end = False
    check = create_matrix(N)
    check2 = create_matrix(N)

    for i in range(N):
        for j in range(10):
            if matrix[i][j] == '0' or check[i][j]:
                continue
            result = dfs(i, j)
            if result >= K:
                dfs2(i, j, matrix[i][j])
                end = True
    
    if not end:
        break
    down()

for i in matrix:
    print(''.join(i))