# 경쟁적 전염(bfs), 바이러스(dfs), 유기농배추(dfs), 효율적인해킹(dfs), MooyoMooyo(dfs), 2048(Easy)(dfs)

from collections import deque

mx, my = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs():
    q = deque(viruses)
    
    while q:
        idx, second, px, py = q.popleft()
        if second == S:
            break
        for i in range(4):
            nx = px + mx[i]
            ny = py + my[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if matrix[nx][ny] == 0:
                matrix[nx][ny] = idx
                q.append((idx, second + 1, nx, ny))

N, K = map(int, input().split())
matrix = []
viruses = []
for i in range(N):
    matrix.append(list(map(int, input().split())))
    for j in range(N):
        if matrix[i][j] != 0:
            viruses.append((matrix[i][j], 0, i, j))
viruses.sort()
S, X, Y = map(int, input().split())
bfs()
print(matrix[X - 1][Y - 1])