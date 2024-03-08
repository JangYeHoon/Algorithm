# fast campus 강의
# https://www.acmicpc.net/problem/1260
# 2

from collections import deque

def dfs(v):
    print(v, end=' ')
    visited[v] = True
    for b in adj[v]:
        if not visited[b]:
            dfs(b)

def bfs(v):
    q = deque()
    q.append(v)
    visited[v] = True
    while q:
        a = q.popleft()
        print(a, end=' ')
        for b in adj[a]:
            if not visited[b]:
                visited[b] = True
                q.append(b)

N, M, V = map(int, input().split())
adj = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
for i in range(1, N + 1):
    adj[i].sort()

visited = [False] * (N + 1)
dfs(V)
print()
visited = [False] * (N + 1)
bfs(V)