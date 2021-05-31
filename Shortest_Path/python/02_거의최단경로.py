import heapq
from collections import deque
import sys
input = sys.stdin.readline

def dijkstra():
    q = []
    heapq.heappush(q, (0, s))
    distance[s] = 0
    while q:
        dist, new = heapq.heappop(q)
        if distance[new] < dist:
            continue
        for next in adj[new]:
            cost = dist + next[1]
            if cost < distance[next[0]] and not dropped[new][next[0]]:
                distance[next[0]] = cost
                heapq.heappush(q, (cost, next[0]))

def bfs():
    q = deque()
    q.append(d)
    while q:
        now = q.popleft()
        if now == s:
            continue
        for prev, cost in reverse_adj[now]:
            if distance[now] == distance[prev] + cost and not dropped[prev][now]:
                dropped[prev][now] = True
                q.append(prev)

while True:
    n, m = map(int, input().split())
    if n == 0:
        break
    adj = [[] for _ in range(n + 1)]
    reverse_adj = [[] for _ in range(n + 1)]

    s, d = map(int, input().split())
    for _ in range(m):
        u, v, p = map(int, input().split())
        adj[u].append((v, p))
        reverse_adj[v].append((u, p))
    
    distance = [1e9] * (n + 1)
    dropped = [[False] * (n + 1) for _ in range(n + 1)]
    dijkstra()

    bfs()

    distance = [1e9] * (n + 1)
    dijkstra()

    if distance[d] != 1e9:
        print(distance[d])
    else:
        print(-1)