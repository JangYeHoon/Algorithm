# fast campus 강의
# https://www.acmicpc.net/problem/1766
# 1

import heapq

n, m = map(int, input().split(' '))
array = [[] for i in range(n + 1)]
indegree = [0] * (n + 1)

heap = []
result = []

for _ in range(m):
    a, b = map(int, input().split(' '))
    array[a].append(b)
    indegree[b] += 1

for i in range(1, n + 1):
    if indegree[i] == 0:
        heapq.heappush(heap, i)

while heap:
    data = heapq.heappop(heap)
    result.append(data)
    for b in array[data]:
        indegree[b] -= 1
        if indegree[b] == 0:
            heapq.heappush(heap, b)

for i in result:
    print(i, end=' ')