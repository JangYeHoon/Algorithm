# 배열돌리기4

from collections import deque
import sys
sys.setrecursionlimit(10000)

mx, my = [1, 0, -1, 0], [0, 1, 0, -1]

def bfs(x, y):
    q = deque([x, y])
    visited[x][y] = True
    while q:
        px = q.popleft()
        py = q.popleft()
        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if matrix[nx][ny] == 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                q.append(nx)
                q.append(ny)

def dfs(x, y):
    visited[x][y] = True
    for i in range(4):
        nx = x + mx[i]
        ny = y + my[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        if matrix[nx][ny] == 1 and not visited[nx][ny]:
            dfs(nx, ny)

for _ in range(int(input())):
    M, N, K = map(int, input().split())
    matrix = [[0] * M for _ in range(N)]
    visited = [[False] * M for _ in range(N)]
    for i in range(K):
        x, y = map(int, input().split())
        matrix[y][x] = 1
    
    result = 0
    for i in range(N):
        for j in range(M):
            if not visited[i][j] and matrix[i][j] == 1:
                result += 1
                dfs(i, j)
    print(result)