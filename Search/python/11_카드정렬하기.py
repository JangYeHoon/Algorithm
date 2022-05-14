# fast campus 강의
# https://www.acmicpc.net/problem/1715
# 2

import heapq

N = int(input())
arr = []
for _ in range(N):
    heapq.heappush(arr, int(input()))

result = 0
while len(arr) > 1:
    a = heapq.heappop(arr)
    b = heapq.heappop(arr)
    result += a + b
    heapq.heappush(arr, a + b)
print(result)