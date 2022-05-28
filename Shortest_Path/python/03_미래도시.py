# 이것이 취업을 위한 코딩테스트다 259p
# 2

N, M = map(int, input().split())
adj = [[1e9] * (N + 1) for _ in range(N + 1)]
for i in range(N + 1):
    for j in range(N + 1):
        if i == j:
            adj[i][j] = 0
for _ in range(M):
    a, b = map(int, input().split())
    adj[a][b] = 1
    adj[b][a] = 1

X, K = map(int, input().split())

for k in range(1, N + 1):
    for a in range(1, N + 1):
        for b in range(1, N + 1):
            adj[a][b] = min(adj[a][b], adj[a][k] + adj[k][b])

dist = adj[1][K] + adj[K][X]
if dist >= 1e9:
    print(-1)
else:
    print(dist)