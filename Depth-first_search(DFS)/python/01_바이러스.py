n = int(input())
m = int(input())
adj = [[] for _ in range(n + 1)]
count = [0] * (n + 1)

for i in range(m):
    start, end = map(int, input().split())
    adj[start].append(end)
    adj[end].append(start)

def dfs(v):
    visited[v] = True
    for e in adj[v]:
        if not(visited[e]):
            count[e] += 1
            dfs(e)

for i in range(1, n + 1):
    visited = [False] * (n + 1)
    dfs(i)

print(max(count))