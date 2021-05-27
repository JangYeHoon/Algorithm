import heapq

def dijkstra(start):
    heap_data = []
    heapq.heappush(heap_data, (0, start))
    distance[start] = 0
    while heap_data:
        dist, new = heapq.heappop(heap_data)
        if distance[new] < dist:
            continue
        for i in adj[new]:
            cost = dist + i[1]
            if distance[i[0]] > cost:
                distance[i[0]] = cost
                heapq.heappush(heap_data, (cost, i[0]))

for _ in range(int(input())):
    n, d, c = map(int, input().split())
    adj = [[] for _ in range(n + 1)]
    distance = [1e9] * (n + 1)

    for _ in range(d):
        a, b, s = map(int, input().split())
        adj[b].append((a, s))

    dijkstra(c)

    count = 0
    max_distance = 0
    for i in distance:
        if i != 1e9:
            count += 1
            if max_distance < i:
                max_distance = i
    print(count, max_distance)