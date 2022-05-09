# fast campus 강의
# https://www.acmicpc.net/problem/1715
# 1

import heapq

n = int(input())

heap = []
for _ in range(n):
    heapq.heappush(heap, int(input()))

result = 0
while len(heap) > 1:
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)
    sum_value = a + b
    result += sum_value
    heapq.heappush(heap, a+b)
print(result)