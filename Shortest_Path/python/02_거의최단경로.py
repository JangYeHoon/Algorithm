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
            cost =  dist + next[1]
            if cost < distance[next[0]]:
                distance[next[0]] = cost
                heapq.heappush(q, (cost, next[0]))

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    s, d = map(int, input().split())
    adj = [[] for _ in range(n)]
    distance = [1e9] * (n)

    for _ in range(m):
        u, v, p = map(int, input().split())
        adj[u].append((v, p))
    
    Dijkstra(s)

    print(distance[d])