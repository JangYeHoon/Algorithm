# 걸그룹마스터준석이, 숨바꼭질, 바이러스(bfs)

from collections import deque

n = int(input())
m = int(input())
adj = [[] for _ in range(n + 1)]

for i in range(m):
    start, end = map(int, input().split())
    adj[start].append(end)
    adj[end].append(start)

def bfs(v):
    global count
    q = deque([v])
    while q:
        v = q.popleft()
        if not(visited[v]):
            visited[v] = True
            count += 1
            for e in adj[v]:
                if not(visited[e]):
                    q.append(e)

visited = [False] * (n + 1)
count = 0
bfs(1)

print(count - 1)