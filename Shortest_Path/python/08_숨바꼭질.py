# 이것이 취업을 위한 코딩테스트다
# 1

import heapq

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
distances = [1e9] * (N + 1)

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append((b, 1))
    graph[b].append((a, 1))

q = []
heapq.heappush(q, (0, 1))
distances[1] = 0
while q:
    dist, now = heapq.heappop(q)

    if distances[now] < dist:
        continue

    for next in graph[now]:
        cost = dist + next[1]
        if cost < distances[next[0]]:
            heapq.heappush(q, (cost, next[0]))
            distances[next[0]] = cost

max_dist = 0
result_node = 0
result = []
for i in range(1, N + 1):
    if max_dist < distances[i]:
        result_node = i
        max_dist = distances[i]
        result = [result_node]
    elif max_dist == distances[i]:
        result.append(i)

print(result_node, max_dist, len(result))
