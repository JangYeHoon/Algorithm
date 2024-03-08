# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/11404
# 1

INF = int(1e9)

n = int(input())
m = int(input())
adj = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            adj[i][j] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    if c < adj[a][b]:
        adj[a][b] = c

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if adj[i][j] == INF:
            print(0, end=' ')
        else:
            print(adj[i][j], end=' ')
    print()
