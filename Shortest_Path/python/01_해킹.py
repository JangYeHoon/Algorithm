# fast campus 강의
# https://www.acmicpc.net/problem/10282
# 2

import heapq

def Dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, new = heapq.heappop(q)
        if distance[new] < dist:
            continue
        for next in adj[new]:
            cost = dist + next[1]
            if cost < distance[next[0]]:
                distance[next[0]] = cost
                heapq.heappush(q, (cost, next[0]))

for _ in range(int(input())):
    n, d, c = map(int, input().split())
    adj = [[] for _ in range(n + 1)]
    distance = [1e9] * (n + 1)

    for _ in range(d):
        a, b, s = map(int, input().split())
        adj[b].append((a, s))
    
    Dijkstra(c)

    count = 0
    max_distance = 0
    for dist in distance:
        if dist != 1e9:
            count += 1
            if max_distance < dist:
                max_distance = dist
    print(count, max_distance)