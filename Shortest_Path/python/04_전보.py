# 이것이 취업을 위한 코딩테스트다
# 1

import heapq

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    d[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if dist > d[now]:
            continue
        for x in adj[now]:
            next_dist = dist + x[1]
            if next_dist < d[x[0]]:
                d[x[0]] = next_dist
                heapq.heappush(q, (next_dist, x[0]))

N, M, C = map(int, input().split())
adj = [[] for _ in range(N + 1)]
d = [1e9] * (N + 1)

for _ in range(M):
    x, y, z = map(int, input().split())
    adj[x].append((y, z))

dijkstra(C)

count = 0
max_dist = 0
for i in d:
    if i != 1e9:
        count += 1
        max_dist = max(max_dist, i)

print(count - 1, max_dist)