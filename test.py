# 효율적인해킹(bfs), 특정 거리의 도시 찾기(bfs), 경쟁적 전염(bfs), 바이러스(dfs), 유기농배추(dfs)

from collections import deque

mx = [-1, 1, 0, 0]
my = [0, 0, -1, 1]

def bfs(x, y):
    q = deque([x, y])
    while q:
        px = q.popleft()
        py = q.popleft()
        if not(visited[px][py]):
            visited[px][py] = True
            for i in range(4):
                nx = px + mx[i]
                ny = py + my[i]
                if nx < 0 or nx >= n or ny < 0 or ny >= m:
                    continue
                if matrix[nx][ny] and not(visited[nx][ny]):
                    q.append(nx)
                    q.append(ny)

for _ in range(int(input())):
    m, n, k = map(int, input().split())
    matrix = [[0] * m for _ in range(n)]
    visited = [[False] * m for _ in range(n)]

    for _ in range(k):
        y, x = map(int, input().split())
        matrix[x][y] = 1
    result = 0
    for i in range(n):
        for j in range(m):
            if matrix[i][j] and not(visited[i][j]):
                bfs(i, j)
                result += 1
    print(result)