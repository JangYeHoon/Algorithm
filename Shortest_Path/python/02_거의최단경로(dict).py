from collections import deque
import heapq
import sys
input = sys.stdin.readline

def Dijkstra():
    heap_data = []
    heapq.heappush(heap_data, (0, start))
    distance[start] = 0
    while heap_data:
        dist, now = heapq.heappop(heap_data)
        if distance[now] < dist:
            continue
        for i in adj[now]:
            cost = dist + adj[now][i]
            if distance[i] > cost:
                distance[i] = cost
                heapq.heappush(heap_data, (cost, i))

def bfs():
    q = deque()
    q.append(end)
    while q:
        now = q.popleft()
        if now == start:
            continue
        for prev, cost in reverse_adj[now]:
            if distance[now] == distance[prev] + adj[prev][now]:
                if (prev, now) not in dropped:
                    dropped.append((prev, now))
                    q.append(prev)

while True:
    n, m = map(int, input().split())
    if n == 0:
        break
    start, end = map(int, input().split())
    adj = [dict() for _ in range(n + 1)]
    reverse_adj = [[] for _ in range(n + 1)]
    
    for _ in range(m):
        x, y, cost = map(int, input().split())
        adj[x][y] = cost
        reverse_adj[y].append((x, cost))
    
    distance = [1e9] * (n + 1)
    Dijkstra()

    dropped = list()
    bfs()

    for u, v in dropped:
        del adj[u][v]

    distance = [1e9] * (n + 1)
    Dijkstra()
    
    if distance[end] != 1e9:
        print(distance[end])
    else:
        print(-1)