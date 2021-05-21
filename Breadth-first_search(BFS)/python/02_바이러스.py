from collections import deque

n = int(input())
m = int(input())
adj = [[] for _ in range(n + 1)]
count = [-1] * (n + 1)

for i in range(m):
    start, end = map(int, input().split())
    adj[start].append(end)
    adj[end].append(start)

def bfs(v):
    q = deque([v])
    while q:
        v = q.popleft()
        if not(visited[v]):
            visited[v] = True
            count[v] += 1
            for e in adj[v]:
                if not(visited[e]):
                    q.append(e)

for i in range(1, n + 1):
    visited = [False] * (n + 1)
    bfs(i)

print(max(count))