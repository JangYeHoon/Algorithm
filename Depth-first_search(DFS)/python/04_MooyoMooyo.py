# fast campus 강의
# https://www.acmicpc.net/problem/16768
# 2

N, K = map(int, input().split())
matrix = [list(input()) for _ in range(N)]
visited = [[False] * 10 for _ in range(N)]
visited2 = [[False] * 10 for _ in range(N)]
mx = [-1, 1, 0, 0]
my = [0, 0, -1, 1]

def dfs(x, y, cnt):
    visited[x][y] = True
    for i in range(4):
        nx = x + mx[i]
        ny = y + my[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= 10:
            continue
        if not(visited[nx][ny]) and matrix[x][y] == matrix[nx][ny]:
            cnt = dfs(nx, ny, cnt + 1)
    return cnt

def dfs2(x, y):
    visited2[x][y] = True
    for i in range(4):
        nx = x + mx[i]
        ny = y + my[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= 10:
            continue
        if not(visited2[nx][ny]) and matrix[x][y] == matrix[nx][ny]:
            dfs2(nx, ny)
    matrix[x][y] = '0'

def down():
    for y in range(10):
        tmp_list = []
        for x in range(N):
            if matrix[x][y] != '0':
                tmp_list.append(matrix[x][y])
        for x in range(N - len(tmp_list)):
            matrix[x][y] = '0'
        for x in range(len(tmp_list)):
            matrix[x + N - len(tmp_list)][y] = tmp_list[x]

while 1:
    chk = False
    visited = [[False] * 10 for _ in range(N)]
    visited2 = [[False] * 10 for _ in range(N)]
    for i in range(N):
        for j in range(10):
            if not(visited[i][j]) and matrix[i][j] != '0':
                cnt = dfs(i, j, 1)
                if cnt >= K:
                    chk = True
                    dfs2(i, j)
    if not(chk):
        break
    down()

for i in matrix:
    print(''.join(i))