# 이것이 취업을 위한 코딩테스트다
# https://www.acmicpc.net/problem/1715
# 1

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
