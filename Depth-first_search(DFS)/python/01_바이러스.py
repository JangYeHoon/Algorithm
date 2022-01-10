# fast campus 강의
# https://www.acmicpc.net/problem/2606
# 1

n = int(input())
m = int(input())
adj = [[] for _ in range(n + 1)]
count = 0

for i in range(m):
    start, end = map(int, input().split())
    adj[start].append(end)
    adj[end].append(start)

def dfs(v):
    global count
    visited[v] = True
    for e in adj[v]:
        if not(visited[e]):
            count += 1
            dfs(e)

visited = [False] * (n + 1)
dfs(1)

print(count)