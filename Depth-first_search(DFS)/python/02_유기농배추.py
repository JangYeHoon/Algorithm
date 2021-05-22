import sys
sys.setrecursionlimit(10000)

T = int(input())
mx = [1, -1, 0, 0]
my = [0, 0, -1, 1]

def dfs(x, y):
    visited[x][y] = True
    for i in range(4):
        nx = x + mx[i]
        ny = y + my[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if adj[nx][ny] == 1 and not(visited[nx][ny]):
            dfs(nx, ny)

result = [0] * T

for t in range(T):
    m, n, k = map(int, input().split())
    adj = [[0] * (m) for _ in range(n)]
    visited = [[False] * (m) for _ in range(n)]
    for _ in range(k):
        x, y = map(int, input().split())
        adj[y][x] = 1

    for i in range(n):
        for j in range(m):
            if adj[i][j] == 1 and not(visited[i][j]):
                dfs(i, j)
                result[t] += 1

for i in range(T):
    print(result[i])