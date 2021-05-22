from collections import deque

T = int(input())
result = [0] * T
mx = [1, -1, 0, 0]
my = [0, 0, 1, -1]

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
                if adj[nx][ny] == 1 and not(visited[nx][ny]):
                    q.append(nx)
                    q.append(ny)

for t in range(T):
    m, n, k = map(int, input().split())
    adj = [[0] * m for _ in range(n)]
    visited = [[False] * m for _ in range(n)]

    for _ in range(k):
        x, y = map(int, input().split())
        adj[y][x] = 1

    for i in range(n):
        for j in range(m):
            if adj[i][j] == 1 and not(visited[i][j]):
                bfs(i, j)
                result[t] += 1

for i in range(T):
    print(result[i])